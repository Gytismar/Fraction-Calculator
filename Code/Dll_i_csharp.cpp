#include "pch.h"
#include "attempt.h"
#include "fractioncalculator.h"
#include <iostream>

auto temp = new(cFraction);

//Fraction calculator
extern "C" __declspec(dllexport) void* CreateFractionCaclculator() {return (void*) new cFractionCalculator();}
extern "C" __declspec(dllexport) void m_PushFraction(cFractionCalculator * FractionCalculator, cFraction& pointer) { return FractionCalculator->m_PushFraction(pointer); }
extern "C" __declspec(dllexport) cFraction* m_GetSum(cFractionCalculator * FractionCalculator) 
{
	cFraction* f = new cFraction;
	*f = FractionCalculator->m_GetSum();
	return f;
}
//extern "C" __declspec(dllexport) cFraction m_GetSum(cFractionCalculator * FractionCalculator) { return FractionCalculator-> m_GetSum(); }
extern "C" __declspec(dllexport) unsigned m_GetGCD(cFractionCalculator * FractionCalculator)  { return FractionCalculator-> m_GetGCD(); }
extern "C" __declspec(dllexport) unsigned m_GetLCM(cFractionCalculator * FractionCalculator)  { return FractionCalculator-> m_GetLCM(); }




//Fractions
extern "C" __declspec(dllexport) void* CreateFraction() { return (void*) new cFraction(); }
extern "C" __declspec(dllexport) void* CreateFractionWithNumbers(short Numerator, short Denominator) { return (void*) new cFraction(Numerator, Denominator); }
extern "C" __declspec(dllexport) void m_SetFraction(cFraction * Fraction, short Numerator, short Denominator) {return Fraction->m_SetFraction(Numerator, Denominator); }
extern "C" __declspec(dllexport) unsigned m_GetNumerator(cFraction * Fraction) { return Fraction->m_GetNumerator(); }
extern "C" __declspec(dllexport) unsigned m_GetDenominator(cFraction * Fraction) { return Fraction->m_GetDenominator(); }
extern "C" __declspec(dllexport) short m_GetSign(cFraction * Fraction) { return Fraction->m_GetSign(); }
extern "C" __declspec(dllexport) double m_GetDecimal (cFraction * Fraction) {return Fraction->m_GetDecimal();}
extern "C" __declspec(dllexport) void m_ResetFractionCount(cFraction * Fraction) {return Fraction->m_ResetFractionCount();}


