using System;
using System.Runtime.InteropServices;

namespace Calculation
{
    public class Skaiciuoti
    {
        //Skaiciuotuvas
        [DllImport("Dll_i_csharp.dll", CallingConvention = CallingConvention.Cdecl)] public static extern IntPtr CreateFractionCaclculator();
        [DllImport("Dll_i_csharp.dll", CallingConvention = CallingConvention.Cdecl)] public static extern void m_PushFraction(IntPtr a, IntPtr b);
        [DllImport("Dll_i_csharp.dll", CallingConvention = CallingConvention.Cdecl)] public static extern IntPtr m_GetSum(IntPtr FractionCalculator);
        [DllImport("Dll_i_csharp.dll", CallingConvention = CallingConvention.Cdecl)] public static extern uint m_GetGCD(IntPtr FractionCalculator);
        [DllImport("Dll_i_csharp.dll", CallingConvention = CallingConvention.Cdecl)] public static extern uint m_GetLCM(IntPtr FractionCalculator);




        //Trupmena
        [DllImport("Dll_i_csharp.dll", CallingConvention = CallingConvention.Cdecl)] public static extern IntPtr CreateFraction();
        [DllImport("Dll_i_csharp.dll", CallingConvention = CallingConvention.Cdecl)] public static extern IntPtr CreateFractionWithNumbers(short Numerator, short Denominator);
        [DllImport("Dll_i_csharp.dll", CallingConvention = CallingConvention.Cdecl)] public static extern void m_SetFraction(IntPtr Fraction, short Numerator, short Denominator);
        [DllImport("Dll_i_csharp.dll", CallingConvention = CallingConvention.Cdecl)] public static extern uint m_GetNumerator(IntPtr Fraction);
        [DllImport("Dll_i_csharp.dll", CallingConvention = CallingConvention.Cdecl)] public static extern uint m_GetDenominator(IntPtr Fraction);
        [DllImport("Dll_i_csharp.dll", CallingConvention = CallingConvention.Cdecl)] public static extern short m_GetSign(IntPtr Fraction);
        [DllImport("Dll_i_csharp.dll", CallingConvention = CallingConvention.Cdecl)] public static extern double m_GetDecimal(IntPtr Fraction);
        [DllImport("Dll_i_csharp.dll", CallingConvention = CallingConvention.Cdecl)] public static extern void m_ResetFractionCount(IntPtr Fraction);
        
        public unsafe void Calculate(short Num1, short Den1, short Num2, short Den2, ref uint Numerator, ref uint Denominator, ref short Sign, ref double Decimal,ref uint GCD, ref uint LCM)
        {
            IntPtr pirma_trump = CreateFractionWithNumbers(Num1, Den1);
            IntPtr antra_trump = CreateFractionWithNumbers(Num2, Den2);

            IntPtr Skaicuotuvas = CreateFractionCaclculator();
            m_PushFraction(Skaicuotuvas, pirma_trump);
            m_PushFraction(Skaicuotuvas, antra_trump);

            IntPtr rez_trump = m_GetSum(Skaicuotuvas);

            Numerator = m_GetNumerator(rez_trump);
            Denominator = m_GetDenominator(rez_trump);
            Sign = m_GetSign(rez_trump);
            Decimal = m_GetDecimal(rez_trump);

            GCD = m_GetGCD(Skaicuotuvas);
            LCM = m_GetLCM(Skaicuotuvas);
        }

        bool IsDigitsOnly(string str)
        {
            foreach (char c in str)
            {
                if ((c < '0' || c > '9') && c != '-' && c != '+')
                    return false;
            }

            return true;
        }

        public void Patikra (string Numerator1, string Denominator1, string Numerator2, string Denominator2, ref bool isNulio, ref bool lestina)
        {
            if (Denominator1 == "0" || Denominator2 == "0")
            {
                isNulio = true;
                lestina = false;
            }  
            else
                isNulio = false;
        }
    }
}
