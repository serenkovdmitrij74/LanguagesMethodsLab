using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab3
{
    public class OctalNumber 
    {
        private string _value;

        public string Value
        {
            get { return _value; }
            set
            {
                if (!IsValidOctal(value)) throw new ArgumentException("Строка должна содержит не восьмеричные цифры");
                _value = value;
            }
        }
        public OctalNumber()
        {
            _value = "0";
        }

        public OctalNumber(string value)
        {
            Value = value;
        }

        public OctalNumber(OctalNumber other)
        {
            if (other == null) throw new ArgumentException("Аргумент не должен равняться нул");
            this._value = other._value;
        }

        private bool IsValidOctal(string str)
        {
            if (string.IsNullOrEmpty(str)) return false;
            foreach (char i in str)
            {
                if (i < '0' || i > '7') return false;
            }
            return true;
        }

        public static implicit operator OctalNumber(string s)
        {
            return new OctalNumber(s);
        }

        public int this[int i]
        {
            get
            {
                if (i < 0 || i >= _value.Length) throw new ArgumentException("Индекс выходит за границы числа");
                return _value[i] - '0';
            }
        }

        public int ToDecimal()
        {
            int result = 0;
            string value = this.Value;

            foreach(char i in value)
            {
                result = result * 8 + i -'0';
            }

            return result;
        }

        public static OctalNumber ToOctal(int num)
        {
            if (num == 0) return new OctalNumber("0");

            string value = "";
            int n = 0;
 
            while (num > 0)
            {
                value += (num % 8);
                num /= 8;
                n++;
            }


            string res = "";
            for (int j = 0; j < n; j++) res+= value[n - j - 1];

            return res;
        }

        public override string ToString()
        {
            return _value;
        }

        public static bool operator ==(OctalNumber a, OctalNumber b)
        {
            if (a is null || b is null) return (a is null && b is null);
            return a.ToDecimal() == b.ToDecimal();
        }

        public static bool operator !=(OctalNumber a, OctalNumber b)
        {
            return !(a == b);
        }

        public static bool operator <(OctalNumber a, OctalNumber b)
        {
            if (a is null || b is null) return false;
            return a.ToDecimal() < b.ToDecimal();
        }

        public static bool operator >(OctalNumber a, OctalNumber b)
        {
            if (a is null || b is null) return false;
            return a.ToDecimal() > b.ToDecimal();
        }

        public static bool operator <=(OctalNumber a, OctalNumber b)
        {
            if (a is null || b is null) return false;
            return a.ToDecimal() <= b.ToDecimal();
        }

        public static bool operator >=(OctalNumber a, OctalNumber b)
        {
            if (a is null || b is null) return false;
            return a.ToDecimal() >= b.ToDecimal();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            OctalNumber a = new OctalNumber("10");
            OctalNumber b = new OctalNumber(a);
            OctalNumber c = "20";


            Console.WriteLine(a[1]);
            Console.WriteLine($"{a.Value} в десятичной ситсеми {a.ToDecimal()}");
            Console.WriteLine($"Форматный вывод {a.ToString()}");

            Console.WriteLine($"a=c{a == c}");
            Console.WriteLine($"a!= b{a != b}");
            Console.WriteLine($"a<b{a < b}");
            Console.WriteLine($"b>{b > a}");
            Console.WriteLine($"a<=c{a <= c}");
            Console.WriteLine($"b>= c{b >= c}");

        }
    }
}
