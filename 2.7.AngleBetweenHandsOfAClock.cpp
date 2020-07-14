class Solution
{
public:
    double angleClock(int hour, int minutes)
    {

        if (hour < 0 || minutes < 0 || hour > 12 || minutes > 60)
            return 0.0;

        if (hour == 12)
            hour = 0;
        if (minutes == 60)
        {
            minutes = 0;
            hour += 1;
            if (hour > 12)
                hour = 0;
        }

        double minute_angle = minutes * 6;
        double hour_angle = 0.5 * (hour * 60 + minutes);

        //         cout<<"minute_angle: "<<minute_angle<<endl;
        //         cout<<"hour_angle: "<<hour_angle<<endl;
        double angle = abs(minute_angle - hour_angle);
        return min(angle, 360 - angle);
    }
};

/*
class Solution {
public:
    double angleClock(int hour, int minutes) {
        float h=(hour*30)+minutes*0.5;
        //float h=((hourminutes%360)*0.5);
        int m=minutes*6;
        float angle=abs(h-m);
        if(angle>180)
            angle=360-angle;
        return angle;
    }
};
*/