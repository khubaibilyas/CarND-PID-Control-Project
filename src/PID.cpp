#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  
  this->Kp = Kp_;
  this->Ki = Ki_;
  this->Kd = Kd_;
  
  p_error = 0;
  i_error = 0;
  d_error = 0;
  
  prev_cte = 0;
  int_cte = 0;
  diff_cte = 0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  
  int_cte += cte;
  diff_cte = cte - prev_cte;
  prev_cte = cte;

  this->p_error = -Kp *  cte;
  this->i_error = -Ki * (int_cte);
  this->d_error = -Kd * (diff_cte);

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return (p_error + i_error + d_error);  // TODO: Add your total error calc here!
}