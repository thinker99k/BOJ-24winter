#include <iostream>
#include <cstring>

using namespace std;

bool gear[4][8];

int checkConnect() {
    int ret = 0;
    
    // 기어 01, 12, 23 맞물리는 곳 비교
    for (int i = 0; i <= 2; i++) {
        if (gear[i][2] != gear[i + 1][6]) {
            ret += 1 << (2 - i);
        }
    }
    
    return ret;
}

bool tmp[8];

// 기어 반시계방향 45도 회전
void gearLeft(int gearnum) {
    // 기어[1]~[7] -> tmp[0]~[6]
    for (int i = 0; i <= 6; i++) {
        tmp[i] = gear[gearnum][i + 1];
    }
    // 기어[0] -> tmp[7]
    tmp[7] = gear[gearnum][0];
    
    // tmp -> gear
    for (int i = 0; i <= 7; i++) {
        gear[gearnum][i] = tmp[i];
    }
}

// 기어 시계방향 45도 회전
void gearRight(int gearnum) {
    // 기어[0]~[6] -> tmp[1]~[7]
    for (int i = 1; i <= 7; i++) {
        tmp[i] = gear[gearnum][i - 1];
    }
    // 기어[7] -> tmp[0]
    tmp[0] = gear[gearnum][7];
    
    // tmp -> gear
    for (int i = 0; i <= 7; i++) {
        gear[gearnum][i] = tmp[i];
    }
}

// -1 반시계, 0 회전없음, 1 시계
int lr[4];
int revdir;

void operateGear(int gearnum, int dir) {
    memset(lr, 0, sizeof(int) * 4);
    
    // 매개변수 dir은 무조건 1 or -1이기에, revdir은 무조건 -1 or 1, 0일 수 없음
    revdir = dir * -1;
    
    switch (checkConnect()) {
        case 0: {
            /**  x x x
             *  0 1 2 3
             */
            // 전부 다 연결되어있지 않음으로 해당 기어만 돌림
            lr[gearnum] = dir;
            break;
        }
        
        case 1: {
            /**  x x o
             *  0 1 2=3
             */
            if (gearnum == 2) {
                lr[2] = dir;
                lr[3] = revdir;
            }
            else if (gearnum == 3) {
                lr[3] = dir;
                lr[2] = revdir;
            }
            else {
                // 해당 기어만 돌림
                lr[gearnum] = dir;
            }
            break;
        }
        
        case 2: {
            /**  x o x
             *  0 1=2 3
             */
            if (gearnum == 1) {
                lr[1] = dir;
                lr[2] = revdir;
            }
            else if (gearnum == 2) {
                lr[2] = dir;
                lr[1] = revdir;
            }
            else {
                // 해당 기어만 돌림
                lr[gearnum] = dir;
            }
            break;
        }
        
        case 4: {
            /**  o x x
             *  0=1 2 3
             */
            if (gearnum == 0) {
                lr[0] = dir;
                lr[1] = revdir;
            }
            else if (gearnum == 1) {
                lr[1] = dir;
                lr[0] = revdir;
            }
            else {
                // 해당 기어만 돌림
                lr[gearnum] = dir;
            }
            break;
        }
        
        case 3: {
            /**  x o o
             *  0 1=2=3
             */
            if (gearnum == 1) {
                lr[1] = dir;
                lr[3] = dir;
                lr[2] = revdir;
            }
            else if (gearnum == 2) {
                lr[2] = dir;
                lr[1] = revdir;
                lr[3] = revdir;
            }
            else if (gearnum == 3) {
                lr[3] = dir;
                lr[1] = dir;
                lr[2] = revdir;
            }
            else {
                lr[0] = dir;
            }
            break;
        }
        
        case 6: {
            /**  o o x
             *  0=1=2 3
             */
            if (gearnum == 0) {
                lr[0] = dir;
                lr[2] = dir;
                lr[1] = revdir;
            }
            else if (gearnum == 1) {
                lr[1] = dir;
                lr[0] = revdir;
                lr[2] = revdir;
            }
            else if (gearnum == 2) {
                lr[2] = dir;
                lr[0] = dir;
                lr[1] = revdir;
            }
            else {
                lr[3] = dir;
            }
            break;
        }
        
        case 5: {
            /**  o x o
             *  0=1 2=3
             */
            if (gearnum == 0) {
                lr[0] = dir;
                lr[1] = revdir;
            }
            else if (gearnum == 1) {
                lr[1] = dir;
                lr[0] = revdir;
            }
            else if (gearnum == 2) {
                lr[2] = dir;
                lr[3] = revdir;
            }
            else {
                lr[3] = dir;
                lr[2] = revdir;
            }
            break;
        }
        
        case 7: {
            /**  o o o
             *  0=1=2=3
             */
            if (gearnum == 0) {
                lr[0] = dir;
                lr[2] = dir;
                lr[1] = revdir;
                lr[3] = revdir;
            }
            else if (gearnum == 1) {
                lr[1] = dir;
                lr[3] = dir;
                lr[0] = revdir;
                lr[2] = revdir;
            }
            else if (gearnum == 2) {
                lr[2] = dir;
                lr[0] = dir;
                lr[1] = revdir;
                lr[3] = revdir;
            }
            else {
                lr[3] = dir;
                lr[1] = dir;
                lr[0] = revdir;
                lr[2] = revdir;
            }
            break;
        }
        
        default: {
            // 실행되면 안됨
            ;
        }
    }
    
    // 4개의 기어의 정해진 움직임 방향으로 회전
    for (int i = 0; i < 4; i++) {
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
}

int score() {
    int ret = 0;
    
    for (int i = 0; i < 4; i++) {
        // 각 기어의 12시방향([0]) 체크
        ret += ((int) gear[i][0]) << i;
    }
    
    return ret;
}

int main() {
    char buf[8];
    for (int i = 0; i < 4; i++) {
        cin >> buf;
        
        for (int j = 0; j < 8; j++) {
            gear[i][j] = (bool)(buf[j] - '0');
        }
    }
    
    int n;
    cin >> n;
    
    int gearnum, direction;
    for (int i = 0; i < n; i++) {
        cin >> gearnum >> direction;
        
        operateGear(gearnum - 1, direction);
    }
    
    cout << score();
    
}