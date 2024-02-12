/*
    문제 백준이는 동생에게 "가운데를 말해요" 게임을 가르쳐주고 있다. 백준이가 정수를 하나씩 외칠때마다 동생은 지금까지
    백준이가 말한 수 중에서 중간값을 말해야 한다. 만약, 그동안 백준이가 외친 수의 개수가
    짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.
    예를 들어 백준이가 동생에게 1, 5, 2, 10, -99, 7, 5를 순서대로 외쳤다고 하면, 동생은 1, 1, 2, 2, 2, 2, 5를 차례대로 말해야 한다.
    백준이가 외치는 수가 주어졌을 때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오
    입력 
    첫째 줄에는 백준이가 외치는 정수의 개수 N이 주어진다.
    N은 1보다 크거나 같고,
    100,000보다 작거나 같은 자연수이다.
    그 다음 N줄에 걸쳐서 백준이가 외치는 정수가 차례대로 주어진다.정수는 - 10,000보다 크거나 같고, 10, 000보다 작거나 같다. */

#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  priority_queue<int> max; // 작은것들의 max값이 top
  priority_queue<int, vector<int>, greater<int>> min; // 큰것들의 min값이 top

  while (t--) {
    int a, size;
    cin >> a;
    if (max.size() == min.size()) {
      max.push(a);
    } else {
      min.push(a);
    }
    if (!max.empty() && !min.empty() && max.top() > min.top()) {
      int max_val, min_val;
      max_val = max.top();
      min_val = min.top();
      max.pop();
      min.pop();
      max.push(min_val);
      min.push(max_val);
    }
    cout << max.top() << '\n';
  }

  return 0;
}