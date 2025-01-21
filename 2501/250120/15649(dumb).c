#include <stdio.h>
#include <stdbool.h>

#define START 1

int n, m;
bool checked[9];

void func1() {
    int it1;
    
    for (it1 = START; it1 <= n; it1++) {
        if (!checked[it1]) {
            printf("%d\n",
                   it1);
        }
    }
}

void func2() {
    int it1, it2;
    
    for (it1 = START; it1 <= n; it1++) {
        if (!checked[it1]) {
            checked[it1] = true;
            
            for (it2 = START; it2 <= n; it2++) {
                if (!checked[it2]) {
                    printf("%d %d\n",
                           it1, it2);
                }
            }
            
            checked[it1] = false;
        }
    }
}

void func3() {
    int it1, it2, it3;
    
    for (it1 = START; it1 <= n; it1++) {
        if (!checked[it1]) {
            checked[it1] = true;
            
            for (it2 = START; it2 <= n; it2++) {
                if (!checked[it2]) {
                    checked[it2] = true;
                    
                    for (it3 = START; it3 <= n; it3++) {
                        if (!checked[it3]) {
                            printf("%d %d %d\n",
                                   it1, it2, it3);
                        }
                    }
                    
                    checked[it2] = false;
                }
            }
            
            checked[it1] = false;
        }
    }
}

void func4() {
    int it1, it2, it3, it4;
    
    for (it1 = START; it1 <= n; it1++) {
        if (!checked[it1]) {
            checked[it1] = true;
            
            for (it2 = START; it2 <= n; it2++) {
                if (!checked[it2]) {
                    checked[it2] = true;
                    
                    for (it3 = START; it3 <= n; it3++) {
                        if (!checked[it3]) {
                            checked[it3] = true;
                            
                            for (it4 = START; it4 <= n; it4++) {
                                if (!checked[it4]) {
                                    printf("%d %d %d %d\n",
                                           it1, it2, it3, it4);
                                }
                            }
                            
                            checked[it3] = false;
                        }
                    }
                    
                    checked[it2] = false;
                }
            }
            
            checked[it1] = false;
        }
    }
}

void func5() {
    int it1, it2, it3, it4, it5;
    
    for (it1 = START; it1 <= n; it1++) {
        if (!checked[it1]) {
            checked[it1] = true;
            
            for (it2 = START; it2 <= n; it2++) {
                if (!checked[it2]) {
                    checked[it2] = true;
                    
                    for (it3 = START; it3 <= n; it3++) {
                        if (!checked[it3]) {
                            checked[it3] = true;
                            
                            for (it4 = START; it4 <= n; it4++) {
                                if (!checked[it4]) {
                                    checked[it4] = true;
                                    
                                    for (it5 = START; it5 <= n; it5++) {
                                        if (!checked[it5]) {
                                            printf("%d %d %d %d %d\n",
                                                   it1, it2, it3, it4, it5);
                                        }
                                    }
                                    
                                    checked[it4] = false;
                                }
                            }
                            
                            checked[it3] = false;
                        }
                    }
                    
                    checked[it2] = false;
                }
            }
            
            checked[it1] = false;
        }
    }
}

void func6() {
    int it1, it2, it3, it4, it5, it6;
    
    for (it1 = START; it1 <= n; it1++) {
        if (!checked[it1]) {
            checked[it1] = true;
            
            for (it2 = START; it2 <= n; it2++) {
                if (!checked[it2]) {
                    checked[it2] = true;
                    
                    for (it3 = START; it3 <= n; it3++) {
                        if (!checked[it3]) {
                            checked[it3] = true;
                            
                            for (it4 = START; it4 <= n; it4++) {
                                if (!checked[it4]) {
                                    checked[it4] = true;
                                    
                                    for (it5 = START; it5 <= n; it5++) {
                                        if (!checked[it5]) {
                                            checked[it5] = true;
                                            
                                            for (it6 = START; it6 <= n; it6++) {
                                                if (!checked[it6]) {
                                                    printf("%d %d %d %d %d %d\n",
                                                           it1, it2, it3, it4, it5, it6);
                                                }
                                            }
                                            
                                            checked[it5] = false;
                                        }
                                    }
                                    
                                    checked[it4] = false;
                                }
                            }
                            
                            checked[it3] = false;
                        }
                    }
                    
                    checked[it2] = false;
                }
            }
            
            checked[it1] = false;
        }
    }
}

void func7() {
    int it1, it2, it3, it4, it5, it6, it7;
    
    for (it1 = START; it1 <= n; it1++) {
        if (!checked[it1]) {
            checked[it1] = true;
            
            for (it2 = START; it2 <= n; it2++) {
                if (!checked[it2]) {
                    checked[it2] = true;
                    
                    for (it3 = START; it3 <= n; it3++) {
                        if (!checked[it3]) {
                            checked[it3] = true;
                            
                            for (it4 = START; it4 <= n; it4++) {
                                if (!checked[it4]) {
                                    checked[it4] = true;
                                    
                                    for (it5 = START; it5 <= n; it5++) {
                                        if (!checked[it5]) {
                                            checked[it5] = true;
                                            
                                            for (it6 = START; it6 <= n; it6++) {
                                                if (!checked[it6]) {
                                                    checked[it6] = true;
                                                    
                                                    for (it7 = START; it7 <= n; it7++) {
                                                        if (!checked[it7]) {
                                                            printf("%d %d %d %d %d %d %d\n",
                                                                   it1, it2, it3, it4, it5, it6, it7);
                                                        }
                                                    }
                                                    
                                                    checked[it6] = false;
                                                }
                                            }
                                            
                                            checked[it5] = false;
                                        }
                                    }
                                    
                                    checked[it4] = false;
                                }
                            }
                            
                            checked[it3] = false;
                        }
                    }
                    
                    checked[it2] = false;
                }
            }
            
            checked[it1] = false;
        }
    }
}

void func8() {
    int it1, it2, it3, it4, it5, it6, it7, it8;
    
    for (it1 = START; it1 <= n; it1++) {
        if (!checked[it1]) {
            checked[it1] = true;
            
            for (it2 = START; it2 <= n; it2++) {
                if (!checked[it2]) {
                    checked[it2] = true;
                    
                    for (it3 = START; it3 <= n; it3++) {
                        if (!checked[it3]) {
                            checked[it3] = true;
                            
                            for (it4 = START; it4 <= n; it4++) {
                                if (!checked[it4]) {
                                    checked[it4] = true;
                                    
                                    for (it5 = START; it5 <= n; it5++) {
                                        if (!checked[it5]) {
                                            checked[it5] = true;
                                            
                                            for (it6 = START; it6 <= n; it6++) {
                                                if (!checked[it6]) {
                                                    checked[it6] = true;
                                                    
                                                    for (it7 = START; it7 <= n; it7++) {
                                                        if (!checked[it7]) {
                                                            checked[it7] = true;
                                                            
                                                            for(it8 = START; it8 <= n; it8++){
                                                                if(!checked[it8]){
                                                                    printf("%d %d %d %d %d %d %d %d\n",
                                                                           it1, it2, it3, it4, it5, it6, it7, it8);
                                                                }
                                                            }
                                                            
                                                            checked[it7] = false;
                                                        }
                                                    }
                                                    
                                                    checked[it6] = false;
                                                }
                                            }
                                            
                                            checked[it5] = false;
                                        }
                                    }
                                    
                                    checked[it4] = false;
                                }
                            }
                            
                            checked[it3] = false;
                        }
                    }
                    
                    checked[it2] = false;
                }
            }
            
            checked[it1] = false;
        }
    }
}

int main() {
    void (*funcarr[9])() = {NULL, func1, func2, func3, func4, func5, func6, func7, func8};
    
    scanf("%d %d", &n, &m);
    getchar();
    
    funcarr[m]();
}