using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ComlexLab
{
    public class Complex
    {
        private float r;
        private float i;

        public Complex(float r=0, float i = 0)
        {
            this.r = r;
            this.i = i;
        }

        public Complex(string str)
        {
            str = str.Replace(" ", "").Replace("i", "").Replace("I", "");

            int index = 0;
            for (int i = 1; i < str.Length; i++) if (str[i] == '-' || str[i] == '+') index = i;

            if (index == 0)
                throw new FormatException("Ошибка при вводе данных");
            else
            {
                string rlStr = str.Substring(0, index);
                string imStr = str.Substring(index);

                if (float.TryParse(rlStr, out float re) && float.TryParse(imStr, out float im))
                {
                    this.r = re;
                    this.i = im;
                }                    
                else
                    throw new FormatException("Введенные данные не являются числами");
            }
        }

        public static Complex operator +(Complex a, Complex b)
        {
            return new Complex(a.r+b.r, a.i+b.i);
        }

        public static Complex operator -(Complex a, Complex b)
        {
            return new Complex(a.r - b.r, a.i - b.i);
        }

        public static Complex operator *(Complex a, Complex b)
        {
            return new Complex((a.r * b.r - a.i * b.i), (a.i * b.r + a.r * b.i));
        }

        public override string ToString()
        {
            string sign = (i > 0) ? "+" : "-";

            return $"{r} {sign} {Math.Abs(i)}i";
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Complex a = new Complex("1 dfs+3i");
            Complex b = new Complex(1, -2);

            Complex c = a+b;
            Console.WriteLine(c);

            c = a - b;
            Console.WriteLine(c);

            c = a * b;
            Console.WriteLine(c);
        }
    }
}