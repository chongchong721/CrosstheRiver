#pragma once
#include <iostream>
class status {
	int ML;
	int CL;
	int BL; //0->right 1->left
public:
	int getML() {
		return this->ML;
	}

	int getCL() {
		return this->CL;
	}
	
	int getBL() {
		return this->BL;
	}

	bool isEqual(status temp) {
		if (temp.BL == BL && temp.ML == ML && temp.CL == CL) {
			return true;
		}
		else {
			return false;
		}
	}

	bool isLeft() {
		if (BL == 1) {
			return true;
		}
		else {
			return false;
		}
	}

	bool ifFinal() {
		if (this->ML == 0 && this->CL == 0 && this->BL == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void set(int m, int c, int b) {
		this->ML = m;
		this->CL = c;
		this->BL = b;
	}

	void printStatus() {
		if (BL == 1) {
			std::cout << "Missionary:" << this->ML << " . Cannibal:" << this->CL << ". Boat: Left" << std::endl;
		}
		else {
			std::cout << "Missionary:" << this->ML << " . Cannibal:" << this->CL << ". Boat: Right" << std::endl;
		}

	}
};

class constraint {
		int M;
		int N;
		int C;
	public:
		int getM() {
			return M;
		}
		int getC() {
			return C;
		}
		int getN() {
			return N;
		}

		void set(int m,int c,int n) {
			this->M = m;
			this->C = c;
			this->N = n;
		}
};