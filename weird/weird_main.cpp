#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 약수 구하기
void CalcDivisor(const int num, vector<int> &divisor);
// 과잉수 체크
bool IsGreaterNum(const int num, const vector<int> &divisor);
// 유사 완전수 체크
bool IsSemiperfect(const int num, const vector<int> &divisor);
// 출력
void PrintDivisor(const vector<int> &divisor);

int main() {
	int testIndex, checkNum;
	vector<int> divisor;

	cin >> testIndex;
	for (int i = 0; i < testIndex; i++) {
		// 스택 초기화
		divisor.clear();
		// weird 판별 숫자 입력
		cin >> checkNum;
		// 약수 계산
		CalcDivisor(checkNum, divisor);

		// 약수들의 합 체크(자기자신 제외)
		if (IsGreaterNum(checkNum, divisor)) {
			cout << "greater!" << endl;
			// 약수들의 합이 원래 수보다 큰지 비교
			if (IsSemiperfect(checkNum, divisor)) {
				cout << "weird" << endl;
			}
			else {
				cout << "not weird" << endl;
			}
		}
		else {
			cout << "not weird" << endl;
		}
		PrintDivisor(divisor);
	}
	return 0;
}

void CalcDivisor(const int num, vector<int> &divisor) {
	int i;
	// 약수의 최대값은 제곱근값보다 작거나 같다
	for (i = 1; (i*i) < num; i++) {
		if ((num%i) == 0) {	// 약수이면
			// 쌍으로 저장
			divisor.push_back(i);
			divisor.push_back((num/i));
		}
	}
	// 제곱수 경우
	if ((i*i) == num) {
		divisor.push_back(i);
	}
	sort(divisor.begin(), divisor.end());
}

bool IsGreaterNum(const int num, const vector<int> &divisor) {
	int sum = 0;
	vector<int> temp = divisor;

	for (int i = 0; i < temp.size()-1; ++i) {
		sum += temp[i];
	}
	if (sum > num) return true;

	return false;
}

bool IsSemiperfect(const int num, const vector<int> &divisor) {
	return false;
}

void PrintDivisor(const vector<int> &divisor) {
	vector<int> temp = divisor;

	cout << "divisor : ";
	for (int i = 0; i < temp.size(); ++i) {
		cout << temp[i] << ",";
	}
	cout << endl;
}