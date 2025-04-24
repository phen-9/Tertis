
#include "holdblock.hpp"
#include <iostream>

using std::cout;

class HoldBlockTest {
public:
	HoldBlockTest();
	void run();
private:
	Holdblock hold;
	Tetromino *testblock;
};

HoldBlockTest::HoldBlockTest() {
	testblock = new SquareBlock();
}

void HoldBlockTest::run() {
	bool hasFailed = false;

	//test that holdblock was properly initialized with nullptr block
	if (hold.getBlock() != nullptr) {
		cout << "HoldBlockTest failed: holdblock was improperly initialized\n";
		hasFailed = true;
	}

	hold.setBlock(testblock);

	//test if holdblock was successfully set to our square
	if (hold.getBlock()->getId() != 0) {
		cout << "HoldBlockTest failed: failed to set holdblock to correct shape\n";
		hasFailed = true;
	}

	if (!hasFailed) {
		cout << "HoldBlockTest Succeeded!\n";
	}


}