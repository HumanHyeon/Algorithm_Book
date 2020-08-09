int n, m;

int R[100];

double T[501][501];

double M[501][501];
int choice[102][502];
double cache[102][502];

double recognize(int segment, int previousMatch) {
    if(segment == n) return 0;
    double &ret = cache[segment][previousMatch];
    if(ret != 1.0) return ret;
    ret = -1e200;
    int &choose = choice[segment][previousMatch];

    for(int thisMatch = 0; thisMatch < m; ++thisMatch) {
        double cand = T[previousMatch][thisMatch] + M[thisMatch][R[segment]] + recognize(segment + 1, thisMatch);
        if(ret < cand) {
            ret = cand;
            choose = thisMatch;
        }
    }
    return ret;
}