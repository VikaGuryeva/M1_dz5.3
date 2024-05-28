#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    // ������������ ��������� ������ ��� ������� �����
    pair<int, bool>* points = new pair<int, bool>[2 * N];

    // ��������� ������� � ��������� �� ����� � ������
    for (int i = 0; i < N; ++i) {
        int left, right;
        cin >> left >> right;
        points[2 * i] = make_pair(left, true);  // ����� ����� �������
        points[2 * i + 1] = make_pair(right, false); // ������ ����� �������
    }

    // ��������� ��� ����� �� ����������
    sort(points, points + 2 * N);

    int painted_length = 0;
    int depth = 0;
    int prev_x = 0;

    // �������� �� ���� ������
    for (int i = 0; i < 2 * N; ++i) {
        int x = points[i].first;
        bool is_left = points[i].second;

        // ��������� ����� ���������� �����, ���� depth �� ����� ���� � ��� �� ������ �����
        if (depth != 0 && x != prev_x) {
            painted_length += x - prev_x;
        }

        // ��������� �������� depth � ����������� �� ����, �������� �� ����� ������� ��� ������ �������
        if (is_left) {
            depth++;
        }
        else {
            depth--;
        }

        // ��������� ���������� ����������
        prev_x = x;
    }

    // ������� ���������
    cout << painted_length << endl;

    // ����������� ���������� ������
    delete[] points;

    return 0;
}
