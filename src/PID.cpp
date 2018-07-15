#include "PID.h"
#include <algorithm>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() :
	p_error(0),
	i_error(0),
	d_error(0),
	cte_prev(0),
	i_MAX(5.0),
	i_MIN(-5.0),
	control_MAX(1.0),
	control_MIN(-1.0)
    {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	PID::Kp = Kp;
	PID::Ki = Ki;
	PID::Kd = Kd;
}

void PID::UpdateError(double cte) {
	p_error = cte;
	i_error += cte;
	
	// saturate integral error
	i_error = max( i_error, i_MIN);
	i_error = min( i_error, i_MAX);

	d_error = cte - cte_prev;
	cte_prev = cte;

	// 
}

double PID::TotalError() {
	double out;
	out = Kp*p_error + Ki*i_error + Kd*d_error;
	out = max( out, control_MIN);
	out = min( out, control_MAX);
	return out;
}

