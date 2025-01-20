#include <iostream>
#include <cstring>

#define DEBUG 1

using namespace std;

bool gear[5][8];

bool tmpgear[8];

// 기어 반시계방향 45도 회전
void gearLeft(int gearnum) {
    // 기어[1]~[7] -> tmp[0]~[6]
    for (int i = 0; i <= 6; i++) {
        tmpgear[i] = gear[gearnum][i + 1];
    }
    // 기어[0] -> tmp[7]
    tmpgear[7] = gear[gearnum][0];
    
    // tmp -> gear
    for (int i = 0; i <= 7; i++) {
        gear[gearnum][i] = tmpgear[i];
    }
}

// 기어 시계방향 45도 회전
void gearRight(int gearnum) {
    // 기어[0]~[6] -> tmp[1]~[7]
    for (int i = 1; i <= 7; i++) {
        tmpgear[i] = gear[gearnum][i - 1];
    }
    // 기어[7] -> tmp[0]
    tmpgear[0] = gear[gearnum][7];
    
    // tmp -> gear
    for (int i = 0; i <= 7; i++) {
        gear[gearnum][i] = tmpgear[i];
    }
}

// -1 반시계, 0 회전없음, 1 시계
int lr[5];
int tmpdir;

bool chkleft(int curgear) {
    return gear[curgear - 1][2] != gear[curgear][6];
}

bool chkright(int curgear) {
    return gear[curgear][2] != gear[curgear + 1][6];
}

void operateGear(int gnum, int dir) {
    memset(lr, 0, sizeof(int) * 5);

#if DEBUG
    cout << "<<<< left search ====\n";
#endif
    
    // i 부터 왼쪽으로 탐색
    tmpdir = dir;
    for (int i = gnum; i >= 2; i--) {
        tmpdir *= -1;
        
        if (chkleft(i)) {
            lr[i - 1] = tmpdir;

#if DEBUG
            cout << "gear[" << i - 1 << "] rotate ";
            if (tmpdir > 0) {
                cout << "right\n";
            }
            else {
                cout << "left\n";
            }
#endif
        
        }
        else {
            break;
        }
    }

#if DEBUG
    cout << "==== right search >>>>\n";
#endif
    
    // i 부터 오른쪽으로 탐색
    tmpdir = dir;
    for (int i = gnum; i <= 3; i++) {
        tmpdir *= -1;
        
        if (chkright(i)) {
            lr[i + 1] = tmpdir;

#if DEBUG
            cout << "gear[" << i + 1 << "] rotate ";
            if (tmpdir > 0) {
                cout << "right\n";
            }
            else {
                cout << "left\n";
            }
#endif
        
        }
        else {
            break;
        }
    }
    
    // 4개 기어 정해진 방향으로 회전
    for (int i = 1; i <= 4; i++) {
        if (lr[i] == 1) {
            // 시계방향
            gearRight(i);
        }
        else if (lr[i] == -1) {
            // 반시계방향
            gearLeft(i);
        }
        else { ;
        }
    }

#if DEBUG
    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < 8; j++) {
            cout << gear[i][j];
        }
        cout << '\n';
    }
#endif

}

int score() {
    int ret = 0;
    
    for (int i = 1; i <= 4; i++) {
        // 각 기어의 12시방향([0]) 체크
        ret += ((int) gear[i][0]) << (i-1);
    }
    
    return ret;
}

int main() {
    char buf[8];
    for (int i = 1; i <= 4; i++) {
        cin >> buf;
        
        for (int j = 0; j <= 7; j++) {
            gear[i][j] = (bool)(buf[j] - '0');
        }
    }
    
    int n;
    cin >> n;
    
    int gearnum, direction;
    for (int i = 0; i < n; i++) {
        cin >> gearnum >> direction;
        
        operateGear(gearnum, direction);
    }
    
    cout << score();
    
}