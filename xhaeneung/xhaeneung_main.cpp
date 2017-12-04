/*입력받은 수식이 맞게 풀어진 것인지 확인하는 프로그램을 작성하라.
대신 답은 순서에 상관없이 개수만 맞으면 정답으로 간주한다.
ex) five -> vife 라도 정답처리*/
#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 40

int convertNum(string str);    //입력받은 영단어를 숫자로 변환
string convertStr(int ans);    //숫자를 영어로 변환
string check(string answer, string write);    //입력받은 값과 계산한 값이 동일한지 체크

int main() {
	int count;    //테스트케이스
	char *insert = new char[MAX_SIZE];    //입력받을 라인
	string line;    //연산을 수행할 문자열
	int A, B;    //영어로 입력받은 수를 숫자로 변환하여 저장할 변수
	char operate;    //산술 기호 저장할 변수
	string C;    //입력한 답
	string answer;    //연산한 결과값의 문자열
	int ans;    //연산한 결과값
	string *result;

	//테스트 케이스 수 입력
	cin >> count;
	result = new string[count];
	cin.ignore();
	//테스트 케이스 수만큼
	for (int i = 0; i<count; i++) {
		//산술식 입력받음
		fgets(insert, MAX_SIZE, stdin);
		line = insert;
		line.pop_back();    //개행문자 삭제

							//입력받은 문자열 쪼개기
							//A
		A = convertNum(line.substr(0, line.find(" ")));
		line.erase(0, line.find(" ") + 1);
		//Operate
		operate = line.at(0);
		line.erase(0, 2);
		//B
		B = convertNum(line.substr(0, line.find(" ")));
		line.erase(0, line.find(" ") + 3);
		//C
		C = line.substr(0);

		//cout<<A<<" "<<operate<<" "<<B<<" "<<C<<endl;
		//cout<<"분리까지 OK"<<endl;

		//연산
		switch (operate) {
		case 43:    //+
			ans = A + B;
			answer = convertStr(ans);
			break;
		case 45:    //-
			ans = A - B;
			answer = convertStr(ans);
			break;
		case 42:    //*
			ans = A*B;
			answer = convertStr(ans);
			break;
		}
		//cout<<"연산까지 OK"<<endl;
		if (ans<0 || ans>10) {    //결과값이 0=<C<=10이 아니라면
			result[i] = "No";
		}
		else {    //입력받은 문자열 C의 길이와 답의 길이가 같을 때만(같지 않으면 답이 아니므로 비교해볼 필요가 없음)
			if (C.length() == answer.length()) result[i] = check(answer, C);
			else result[i] = "No";
		}
	}

	for (int i = 0; i<count; i++) {
		cout << result[i] << endl;
	}

	//할당 해제
	delete[]result;
	delete[]insert;
	return 0;
}

int convertNum(string str) {    //입력받은 영단어를 숫자로 변환
								//2글자만 비교하여 숫자를 판별함
	char num = str.at(0);
	char num_same = str.at(1);

	switch (num) {
	case 122:
		return 0;
	case 111:
		return 1;
	case 116:
		if (num_same == 119) return 2;
		else if (num_same == 104) return 3;
		else return 10;
	case 102:
		if (num_same == 111) return 4;
		else return 5;
	case 115:
		if (num_same == 105) return 6;
		else return 7;
	case 101:
		return 8;
	case 110:
		return 9;
	}
}
string convertStr(int ans) {    //숫자를 영어로 변환
	switch (ans) {
	case 0:
		return "zero";
	case 1:
		return "one";
	case 2:
		return "two";
	case 3:
		return "three";
	case 4:
		return "four";
	case 5:
		return "five";
	case 6:
		return "six";
	case 7:
		return "seven";
	case 8:
		return "eight";
	case 9:
		return "nine";
	case 10:
		return "ten";
	default:
		return "";
	}
}
string check(string answer, string write) {    //입력받은 값과 계산한 값이 동일한지 체크
	int arr_write[26] = { 0, };    //모든 값 0으로 초기화
	int arr_ans[26] = { 0, };
	int index = 0;
	bool check = true;

	for (int i = 0; i<write.length(); i++) {    //각 위치에 글자수 할당
		arr_write[write.at(i) - 97]++;
		arr_ans[answer.at(i) - 97]++;
	}
	while (index<26) {    //배열이 끝날 때까지 비교
		if (arr_write[index] != arr_ans[index]) {    //같지 않은 부분이 있다면
			check = false;
			break;
		}
		index++;
	}

	//모두 겹치면 YES, 아니면 NO
	if (check) return "Yes";
	else return "No";
}