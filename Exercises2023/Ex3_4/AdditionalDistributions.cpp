#include <iostream>
#include <string>
#include <vector>
#include "FiniteFunctions.h"
#include <filesystem> //To check extensions in a nice way
#include "AdditionalDistributions.h"
#include "gnuplot-iostream.h" //Needed to produce plots (not part of the course)
#include <cstdlib>

//Normal Distribution
//Empty constructor
NormalDistribution::NormalDistribution(){
  m_RMin = -5.0; m_RMax = 5.0;
  m_mean = 0; m_std = 1;
  this->checkPath("DefaultFunction");
  m_Integral = NULL;
}
//initialised constructor
NormalDistribution::NormalDistribution(double range_min, double range_max, std::string outfile, double mean, double std){
  m_RMin = range_min;
  m_RMax = range_max;
  m_Integral = NULL;
  m_mean = mean;
  m_std = std;
  this->checkPath(outfile); //Use provided string to name output files
}
//Function itself
double NormalDistribution::normalDist(double x) {
    return (1/((this->m_std)*std::sqrt(2*3.1415)))*std::exp(-0.5*std::pow((x - this->m_mean)/this->m_std,2));
    }
double NormalDistribution::callFunction(double x) {return this->normalDist(x);}; //(overridable)


//CauchyLorentz Distribution
//Empty constructor
CauchyLorentzDistribution::CauchyLorentzDistribution() {
  m_RMin = -5.0; m_RMax = 5.0;
  m_x0 = 0; m_gamma = 0.5;
  this->checkPath("DefaultFunction");
  m_Integral = NULL;
}
//initialised constructor
CauchyLorentzDistribution::CauchyLorentzDistribution(double range_min, double range_max, std::string outfile, double x0, double gamma){
  m_RMin = range_min;
  m_RMax = range_max;
  m_Integral = NULL;
  m_gamma = gamma;
  m_x0 = x0;
  this->checkPath(outfile);
}
//Function itself
double CauchyLorentzDistribution::cauchyLorentzDist(double x) {
    return 1/((3.1415*(this->m_gamma))*(1+(std::pow(((x+(this->m_x0))/(this->m_gamma)),2))));
};
double CauchyLorentzDistribution::callFunction(double x) {return this->cauchyLorentzDist(x);}; //(overridable)

//Negative Crystal Ball Distribution
//Empty constructor
negCrystalBallDistribution::negCrystalBallDistribution() {
  m_RMin = -5.0; m_RMax = 5.0;
  m_n = 0; m_alpha = 0.5;
  this->checkPath("DefaultFunction");
  m_Integral = NULL;
}
//initialised constructor
negCrystalBallDistribution::negCrystalBallDistribution(double range_min, double range_max, std::string outfile, double n, double alpha, double xbar, double sig){
  m_RMin = range_min;
  m_RMax = range_max;
  m_Integral = NULL;
  m_n = n;
  m_alpha = alpha;
  m_xbar = xbar;
  m_sig = sig;
  m_A = std::pow(m_n/abs(m_alpha), m_n) * std::exp(-0.5*std::pow(abs(m_alpha),2));
  m_B = m_n/abs(m_alpha) - abs(m_alpha);
  m_C = (m_n/abs(m_alpha)) * std::pow(m_n-1, -1) * std::exp(-0.5*std::pow(abs(m_alpha),2));
  m_D = std::sqrt(3.1415/2)*(1+abs(m_alpha)/std::sqrt(2));
  m_N = std::pow(m_sig*(m_C+m_D),-1);
  this->checkPath(outfile);
}
//Function itself
double negCrystalBallDistribution::negCrystalBallDist(double x) {
    if ((x - this->m_xbar)/this->m_sig > -1*this->m_alpha) {
        return m_N*std::exp(-std::pow(x-this->m_xbar,2)/(2*std::pow(this->m_sig,2)));
    }
    else {
        return m_N*m_A*std::pow(m_B - (x-this->m_xbar)/this->m_sig,-1*this->m_n);
    }
};
double negCrystalBallDistribution::callFunction(double x) {return this->negCrystalBallDist(x);}; //(overridable)
