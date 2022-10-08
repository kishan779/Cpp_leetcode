class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        float h = (hour%12 + (float)minutes/60)*30;
        
        float m = minutes*6;
        float angle = fabs(h-m);
        if(angle>180) angle =360-angle;
        return angle;
    }
};