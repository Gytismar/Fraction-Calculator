using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Calculation;

namespace WindowsFormTest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        Skaiciuoti cal = new Skaiciuoti();
        bool leistina = true;
        bool badInput = false;
        bool isNulio = false;
        private void Mygtukas_Click(object sender, EventArgs e)
        {
            short Num1 = 0, Den1 = 1, Num2 = 0, Den2 = 1, sign = 1;
            uint Numerator = 0, Denominator = 1, GCD = 0, LCM = 0;
            double Decimal = 0;

            leistina = true;
            if (!(Int16.TryParse(Numerator1.Text, out Num1))) { leistina = false; badInput = true; }
            if (!(Int16.TryParse(Numerator2.Text, out Num2))) { leistina = false; badInput = true; }
            if (!(Int16.TryParse(Denominator1.Text, out Den1))) { leistina = false; badInput = true; }
            if (!(Int16.TryParse(Denominator2.Text, out Den2))) { leistina = false; badInput = true; }

            cal.Patikra(Numerator1.Text, Denominator1.Text, Numerator2.Text, Denominator2.Text, ref isNulio, ref leistina);


            if (leistina)
            {
                cal.Calculate(Num1, Den1, Num2, Den2, ref Numerator, ref Denominator, ref sign, ref Decimal, ref GCD, ref LCM);

                RezNumerator.Text = Numerator.ToString();
                RezDenominator.Text = Denominator.ToString();

                Decimal = Math.Round(Decimal, 4);
                Decimalbox.Text = Decimal.ToString();
                GCDbox.Text = GCD.ToString();
                LCMbox.Text = LCM.ToString();
                ErrorLabel.Text = "";

            }
            else
            {
                if (isNulio)
                    ErrorLabel.Text = "Error: Divide by 0";
                else if (badInput)
                    ErrorLabel.Text = "Error: Bad Input ";

                RezNumerator.Text = "";
                RezDenominator.Text = "";
                Decimalbox.Text = "";
                GCDbox.Text = "";
                LCMbox.Text = "";
            }

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
