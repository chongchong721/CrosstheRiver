#include "status.h"
#include <vector>
#include <algorithm>
void DFS(std::vector<status>*, status,int &,constraint);
bool ifLegal(std::vector<status>*, status, constraint);
int main() {
	int M, C, N;
	int Count = 0;
	std::vector<status>* myStatus = new std::vector<status>();
	myStatus->clear();
	std::cout << "请分别输入传教士、野人、载人数以空格分隔" << std::endl;
	std::cin >> M >> C >> N;
	while(C > M){
		std::cout << "请重新输入野人数，必须小于" << M << std::endl;
		std::cin >> C;
	}
	constraint cons;
	cons.set(M, C, N);
	status init;
	init.set(M, C, 1);
	myStatus->push_back(init);
	DFS(myStatus, init,Count,cons);
	if (Count == 0) {
		std::cout << "无方案" << std::endl;
	}
	else {
		std::cout << "有" << Count << "种方案" << std::endl;
	}
	system("pause");
}

bool ifLegal(std::vector<status>* myStatus, status s, constraint cons) {
	if (!myStatus->empty()) {
		for (auto iterator = myStatus->begin(); iterator != myStatus->end(); iterator++) {
			if (s.isEqual(*iterator)) {
				return false;
			}
		}
	}
	
	if (s.getML() != 0 && s.getML() < s.getCL()) {
		return false;
	}
	if (cons.getM() - s.getML() != 0 && (cons.getM() - s.getML()) < (cons.getC() - s.getCL())) {
		return false;
	}
	return true;
}

void DFS(std::vector<status>* myStatus, status s, int& Count,constraint cons) {
	if (s.ifFinal()) {
		Count++;
		std::cout << "方案" << Count << ":"<<std::endl;
		for (auto iterator = myStatus->begin(); iterator != myStatus->end(); iterator++) {
			std::cout << "(" << (*iterator).getML() << "," << (*iterator).getCL() << "," << (*iterator).getBL() << ")" << std::endl;
		}
	}

	int maxM;
	int maxC;
	if (s.isLeft()) {
		maxM = std::min(s.getML(), cons.getN());
		maxC = std::min(s.getCL(), cons.getN());
	}
	else {
		maxM = std::min(cons.getM() - s.getML(), cons.getN());
		maxC = std::min(cons.getC() - s.getCL(), cons.getN());
	}

	for (int i = 0; i <= maxM; i++) {
		for (int j = 0; j <= std::min(cons.getN() - i, maxC); j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			if (i != 0 && i < j) {
				continue;
			}
			int tempML, tempCL, tempBL;
			status next;
			if (s.isLeft()) {
				tempML = s.getML() - i;
				tempCL = s.getCL() - j;
				tempBL = 0;
				next.set(tempML, tempCL, tempBL);
				if (ifLegal(myStatus, next,cons)) {
					myStatus->push_back(next);
					DFS(myStatus, next, Count, cons);
					for (auto iterator = myStatus->begin(); iterator != myStatus->end(); iterator++) {
						if (next.isEqual((*iterator))) {
							myStatus->erase(iterator);
							break;
						}
					}
				}
			}
			else {
				tempML = s.getML() + i;
				tempCL = s.getCL() + j;
				tempBL = 1;
				next.set(tempML, tempCL, tempBL);
				if (ifLegal(myStatus, next,cons)) {
					myStatus->push_back(next);
					DFS(myStatus, next, Count, cons);
					for (auto iterator = myStatus->begin(); iterator != myStatus->end(); iterator++) {
						if (next.isEqual((*iterator))) {
							myStatus->erase(iterator);
							break;
						}
					}
				}
			}

		}
	}
}
