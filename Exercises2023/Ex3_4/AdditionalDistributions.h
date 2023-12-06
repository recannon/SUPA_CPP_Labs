#include <string>
#include <vector>
#include "gnuplot-iostream.h"
#include "FiniteFunctions.h"
#pragma once //Replacement for IFNDEF

class NormalDistribution : public FiniteFunction {
    public:
        //Constructors
        NormalDistribution();
        NormalDistribution(double range_min, double range_max, std::string outfile, double mean, double std); 
        //Functions
        virtual double callFunction(double x); //Call the function with value x
    protected:
        //Variables
        double m_mean;
        double m_std;
    private:
        double normalDist(double x);
};

class CauchyLorentzDistribution : public FiniteFunction {
    public:
        //Constructors
        CauchyLorentzDistribution();
        CauchyLorentzDistribution(double range_min, double range_max, std::string outfile, double x0, double gamma); 
        //Functions
        virtual double callFunction(double x); //Call the function with value x (Overridable)
    protected:
        //Variables
        double m_gamma;
        double m_x0;
    private:
        double cauchyLorentzDist(double x);
};

class negCrystalBallDistribution : public FiniteFunction {
    public:
        //Constructors
        negCrystalBallDistribution();
        negCrystalBallDistribution(double range_min, double range_max, std::string outfile, double n, double alpha, double xbar, double sig); 
        //Function
        virtual double callFunction(double x); //Call the function with value x (Overridable)
    protected:
        //Variables
        double m_n;
        double m_alpha;
        double m_xbar;
        double m_sig;
    private:
        double m_A, m_B, m_C, m_D, m_N;
        double negCrystalBallDist(double x);
};