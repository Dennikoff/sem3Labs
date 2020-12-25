#include "pch.h"
#include "../Libs/Mission.h"
using namespace MC;
TEST(ConstructorTest, Empty) {
    Mission mis;
    ASSERT_EQ(mis.getStartMoney(), 2000);
    ASSERT_EQ(mis.getFullWeight(), 100);
    ASSERT_EQ(mis.getMaxShip_Pir(), 6);
    ASSERT_EQ(mis.getTime(), 8);
}

TEST(ConstructorTest, InitConstr) {
    Mission mis(Captain(),10000,600,10,15,4);
    ASSERT_EQ(mis.getFullWeight(),600);
    ASSERT_EQ(mis.getStartMoney(),10000);
    ASSERT_EQ(mis.getMaxShip_Con(),10);
}

TEST(SettersTest, SettersMis) {
    Mission mis;
    mis.setFullWeight(1000);
    mis.setStartMoney(9);
    mis.setMoneyLeft(0);
    mis.setDelWeight(1000);
    mis.setCoordA(std::make_pair(10, 10));
    ASSERT_EQ(mis.getFullWeight(), 1000);
    ASSERT_EQ(mis.getStartMoney(), 9);
    ASSERT_EQ(mis.getMoneyLeft(), 0);
    ASSERT_ANY_THROW(mis.setDelWeight(-100));
    ASSERT_EQ(mis.getCoordA(), std::make_pair(10, 10));
}

TEST(FunctionsTest, BuyShipConTest) {
    Mission mis;
    mis.buyCon(1);
    ASSERT_EQ(mis.getMoneyLeft(), 1700);
    mis.buyCon(2);
    mis.buyCon(3);
    Ship* sh;
    sh = mis.getShipCon("a");
    ASSERT_EQ(sh->getType(), "sup");
    sh = mis.getShipCon("b");
    ASSERT_EQ(sh->getType(), "def");
    sh = mis.getShipCon("c");
    ASSERT_EQ(sh->getType(), "mil");
    ASSERT_EQ(mis.getMoneyLeft(), 1100);
    mis.setMoneyLeft(0);
    ASSERT_ANY_THROW(mis.buyCon(1));
    ASSERT_ANY_THROW(mis.buyCon(2));
    ASSERT_ANY_THROW(mis.buyCon(3));
}

TEST(FunctionsTest, BuyWeaponConTest) {
    Mission mis;
    BatArm weapon("1", 1, 100, 100, 100, 100);
    mis.buyCon(1);
    mis.buyCon(2);
    mis.buyCon(3);
    ASSERT_ANY_THROW(mis.buyWeapon("a","Bow",weapon));
    mis.buyWeapon("b", "Bow", weapon);
    mis.buyWeapon("c", "Bow", weapon);
    ASSERT_EQ(mis.getMoneyLeft(), 1100 - 2 * weapon.getPrice());
    mis.buyWeapon("c", "Bow", weapon);
    ASSERT_EQ(mis.getMoneyLeft(), 1100 - 2 * weapon.getPrice());
    mis.setMoneyLeft(0);
    ASSERT_NO_THROW(mis.buyWeapon("b", "Bow", weapon));
    ASSERT_ANY_THROW(mis.buyWeapon("b", "Stern", weapon));
}

TEST(FunctionsTest, CreateShipPirTest) {
    Mission mis;
    mis.setMoneyLeft(0);
    ASSERT_NO_THROW(mis.createShipP());
    ASSERT_NO_THROW(mis.createShipP());
    mis.setMoneyLeft(100);
    mis.createShipP();
    ASSERT_EQ(mis.getMoneyLeft(), 100);
    ASSERT_NO_THROW(mis.getShipPir("1"));
    ASSERT_NO_THROW(mis.getShipPir("2"));
    ASSERT_NO_THROW(mis.getShipPir("3"));
    ASSERT_ANY_THROW(mis.getShipPir("4"));
    ASSERT_ANY_THROW(mis.getShipPir("5"));
}

TEST(FunctionsTest, CreateWeaponPirTest) {
    Mission mis;
    BatArm weapon("1", 1, 100, 100, 100, 100);
    std::string place = "Bow";
    ASSERT_ANY_THROW(mis.createWeapon("1", place, weapon));
    mis.createShipP();
    ASSERT_NO_THROW(mis.createWeapon("1", place, weapon));
}

TEST(FunctionsTest, SellConTest) {
    Mission mis;
    mis.buyCon(1);
    ASSERT_EQ(mis.getMoneyLeft(), 1700);
    mis.buyCon(2);
    mis.buyCon(3);
    ASSERT_EQ(mis.getMoneyLeft(), 1100);
    mis.sellCon("b");
    ASSERT_EQ(mis.getMoneyLeft(), 1400);
    ASSERT_ANY_THROW(mis.sellCon("b"));
}

TEST(FunctionsTest, SellWeaponConTest) {
    Mission mis;
    BatArm weapon("1", 1, 100, 100, 100, 100);
    mis.buyCon(1);
    mis.buyCon(2);
    mis.buyCon(3);
    mis.buyWeapon("b", "Bow", weapon);
    mis.buyWeapon("c", "Bow", weapon);
    ASSERT_ANY_THROW(mis.sellWeapon("a", "Bow"));
    ASSERT_ANY_THROW(mis.sellWeapon("b", "Stern"));
    ASSERT_EQ(mis.getMoneyLeft(), 1100 - 2 * weapon.getPrice());
    ASSERT_NO_THROW(mis.sellWeapon("b", "Bow"));
    ASSERT_EQ(mis.getMoneyLeft(), 1100 - weapon.getPrice());
    ASSERT_NO_THROW(mis.sellWeapon("c", "Bow"));
    ASSERT_EQ(mis.getMoneyLeft(), 1100);
}

TEST(FunctionsTest, DestroyShipConTest) {
    Mission mis;
    mis.buyCon(1);
    mis.buyCon(2);
    ASSERT_EQ(mis.getMoneyLeft(), 1400);
    mis.destroyShipCon("a");
    ASSERT_EQ(mis.getMoneyLeft(), 1400);
    ASSERT_ANY_THROW(mis.destroyShipCon("a"));
}

TEST(FunctionsTest, DestroyShipPirTest) {
    Mission mis;
    mis.createShipP();
    mis.createShipP();
    ASSERT_EQ(mis.getMoneyLeft(), 2000);
    mis.destroyShipPir("1");
    ASSERT_EQ(mis.getMoneyLeft(), 2000);
    ASSERT_ANY_THROW(mis.destroyShipPir("1"));
}

TEST(FunctionsTest, LoadShipTest) {
    Mission mis;
    mis.buyCon(1);
    mis.buyCon(2);
    mis.buyCon(3);
    mis.loadShip("a", 50);
    mis.loadShip("c", 50);
    ASSERT_EQ(mis.getWeigthLeft(), 0);
    mis.setWeightLeft(1000);
    ASSERT_ANY_THROW(mis.loadShip("b", 100));
    ASSERT_ANY_THROW(mis.loadShip("a", 100));
    ASSERT_NO_THROW(mis.loadShip("c", 50));
    ASSERT_EQ(mis.getWeigthLeft(), 950);
    mis.destroyShipCon("c");
    ASSERT_EQ(mis.getLostWeigth(), 100);
}

TEST(FunctionsTest, UnloadShipTest) {
    Mission mis;
    mis.buyCon(1);
    mis.buyCon(2);
    mis.buyCon(3);
    mis.loadShip("a", 50);
    mis.loadShip("c", 50);
    ASSERT_EQ(mis.getWeigthLeft(), 0);
    ASSERT_ANY_THROW(mis.unloadShip("b", 100));
    ASSERT_NO_THROW(mis.unloadShip("a", 100));
    ASSERT_NO_THROW(mis.unloadShip("c", 50));
    ASSERT_EQ(mis.getWeigthLeft(), 100);
    mis.loadShip("a", 100);
    ASSERT_EQ(mis.getWeigthLeft(), 0);
}


int _tmain(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}