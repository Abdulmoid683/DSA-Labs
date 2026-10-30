#include <iostream>
using namespace std;

class Course {
public:
    virtual void duration() = 0; 
};

class OnlineCourse : public Course {
private:
    int weeks;
    int hoursPerWeek;

public:
    OnlineCourse(int w, int h) {
        weeks = w;
        hoursPerWeek = h;
    }

    void duration() override {
        cout << "Online Course Duration:" << endl;
        cout << "Weeks: " << weeks << endl;
        cout << "Hours per Week: " << hoursPerWeek << endl;
        cout << "Total Study Hours: "
            << weeks * hoursPerWeek << " hours" << endl;
    }
};

class OfflineCourse : public Course {
private:
    int months;
    int hoursPerDay;

public:
    OfflineCourse(int m, int h) {
        months = m;
        hoursPerDay = h;
    }

    void duration() override {
        cout << "Offline Course Duration:" << endl;
        cout << "Months: " << months << endl;
        cout << "Hours per Day: " << hoursPerDay << endl;
        cout << "Total Study Hours (assuming 30 days/month): "
            << months * 30 * hoursPerDay << " hours" << endl;
    }
};

int main1() {
    OnlineCourse online(8, 5);
    OfflineCourse offline(3, 4);

    cout << "===== Course Details =====" << endl;

    online.duration();

    cout << endl;

    offline.duration();

    return 0;
}
