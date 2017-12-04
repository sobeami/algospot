/*
	괴짜수(weird number) 찾기
	과잉수(자기 자신을 제외한 약수를 모두 더한 값이 자신보다 큰 수) 중
	유사완전수(인수 가운데 일부를 더한 값이 그 수 자신과 같은 수)가 아닌 수를 찾아라
	괴짜수 예시 : 70, 836, 4030, 5830, 7192, 7912, 9272, ....
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 약수 구하기
void CalcDivisor(const int num, vector<int> &divisor);
// 과잉수 체크
bool IsGreaterNum(const int num, const vector<int> &divisor);
// 유사 완전수 체크
bool IsSemiperfect(const int num, const vector<int> &divisor, const int index);
// 출력
void PrintResult(const vector<bool> &result);

int main() {
	int testIndex, checkNum;
	vector<int> divisor;
	vector<bool> result;

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
			// 약수들의 합이 원래 수보다 큰지 비교
			if (!IsSemiperfect(checkNum, divisor, divisor.size() - 1)) {
				result.push_back(true);
			}
			else {
				result.push_back(false);
			}
		}
		else {
			result.push_back(false);
		}
	}
	PrintResult(result);
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

bool IsSemiperfect(const int num, const vector<int> &divisor, const int index) {
	if (index < 0) {
		return false;
	}

	int sum = 0;
	int i = 0;
	vector<int> temp = divisor;

	for (int i = 0; i < index; ++i) {
		sum += temp[i];
	}

	// 전부 더한 값에서 원래 값을 뺀다.
	int gap = sum - num;
	// 1. gap이 divisor 안에 있는지 확인한다. - 있으면 false 리턴
	int tempSum = 0;
 	for (i = 0; i < index; ++i) {
		if (temp[i] > gap) break;
		if (temp[i] == gap) {
			return true;
		}
		tempSum += temp[i];
	}
	for (int j = 0; j < index; ++j) {
		if ((tempSum - gap) == temp[j]) {
			return true;
		}
	}
	return false;
}

void PrintResult(const vector<bool> &result) {
	for (int i = 0; i < result.size(); ++i) {
		if (result[i]) {
			cout << "weird" << endl;
		}
		else {
			cout << "not weird" << endl;
		}
	}
}