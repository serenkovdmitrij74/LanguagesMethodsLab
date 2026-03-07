using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

public static class MyMath
{
    public static float MyAbs(float num)
    {
        return (num > 0) ? num : -num;
    }

    public static float Ex5Func(float x, int n)
    {
        return MyPow(x, (2*n)+1) / ((2 * n) + 1);
    }

    public static float MyPow(float num, int powNum)
    {
        float result = 1.0f;

        for (;powNum>1; powNum--)
        {
            result *= num;
        }

        return powNum != 0 ? result : 1.0f;
    }

    public static void TaylorForEx5(float[] interval, float dx, float epsilon)
    {
        double chisl = 0, znam = 1;

        Console.WriteLine("значение аргумента | значение функции | количество просуммированных членов ряда");

        for (float x = interval[0]; x < interval[1]; x += dx)
        {
            int n = 0;
            float result = 1, r = Ex5Func(x, n);
            while(MyAbs(r) > epsilon)
            {
                result *= r;
                n++;
                r=Ex5Func(x, n);
            }

            Console.WriteLine($"{x} | {result} | {n}");

        }

    }
}

public static class ReadFile
{
    public static string[] CreateWordMas(string file)
    {
        return File.ReadAllText(file).Split(' ');
    }

    public static string[] CreateStrMas(string file)
    {
        return File.ReadAllLines(file);
    }

    public static int sizeOfLine(string[] lines)
    {
        return lines[0].Split(' ').Length;
    }

    public static int sizeOfLine(string line)
    {
        return line.Split(' ').Length;
    }
}

public static class Matrix
{
    private static float[] StlbToStr(float[][] matrix, int index)
    {
        float[] mas = new float[matrix.Length];
        for (int i = 0; i < matrix.Length; i++)
        {
            mas[i] = matrix[i][index];
        }
        return mas;
    }
    private static int SearchMin(float[] mas)
    {
        int minIndex = 0;

        for (int i = 1; i < mas.Length; i++)
        {
            if(mas[i] < mas[minIndex])
                minIndex = i;
        }

        return minIndex;
    }

    private static int SearchMax(float[] mas)
    {
        int maxIndex = 0;

        for (int i = 1; i < mas.Length; i++)
        {
            if (mas[i] > mas[maxIndex])
                maxIndex = i;
        }

        return maxIndex;
    }

    public static void SearchSedl(float[][] matrix)
    {
        for(int i = 0; i < matrix.Length; i++)
        {
            int min = SearchMin(matrix[i]);
            int max = SearchMax(matrix[i]);

            if (i == SearchMax(StlbToStr(matrix, min)))
                Console.WriteLine($"Точка ({i}, {min}) седловая\n");
            if (i == SearchMin(StlbToStr(matrix, max)))
                Console.WriteLine($"Точка ({i}, {max}) седловая\n");
        }
    }

    public static float[][] CreateMatrix(string file)
    {
        string[] workMas = ReadFile.CreateStrMas(file);
        int x = ReadFile.sizeOfLine(workMas), y = workMas.Length;
        float[][] matrix = new float[x][];

        for (int i = 0; i < x; i++)
        {
            string[] workLine = workMas[i].Split(' ');
            matrix[i] = Array.ConvertAll(workLine, float.Parse);
        }

        return matrix;
    }


    public static void SumElem(float[][] matrix)
    {
        for(int i = 0;i < matrix.Length; i++)
        {
            bool hasNull = false;
            float sum = 0;
            for (int j = 0; j < matrix[i].Length; j++)
            {
                if(matrix[i][j] < 0)
                {
                    hasNull = true;
                    break;
                }
                else
                {
                    sum += matrix[i][j];
                }
            }

            if (!hasNull)
                Console.WriteLine($"Сумма элементов в строке {i + 1} = {sum}");

        }
    }

    public static void PrintMatrix(float[][] matrix)
    {
        for (int i = 0; i < matrix.Length; i++)
        {
            for (int j = 0; j < matrix[i].Length; j++)
            {
                Console.WriteLine(matrix[i][j]);
            }
            Console.WriteLine("\n");
        }
    }
}

public static class Text
{
    public static string WordSwap(string file)
    {
        string[] mas = ReadFile.CreateWordMas(file);

        for (int i = 0; i<mas.Length-1; i+=2)
        {
            string word = mas[i];
            mas[i] = mas[i+1];
            mas[i + 1] = word;
        }

        return string.Join(" ", mas);
    }
}

namespace Lab1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string matrixFile = "C:\\Users\\DmitrijSerenkov\\source\\repos\\Lab1\\Lab1\\matrix.txt";
            string textFile = "C:\\Users\\DmitrijSerenkov\\source\\repos\\Lab1\\Lab1\\text.txt";
            float[][] matrix = Matrix.CreateMatrix(matrixFile);
            float[] interval = { -0.9f, 0.9f };
            string text = Text.WordSwap(textFile);

            MyMath.TaylorForEx5(interval, 0.1f, 0.01f);
        }
    }
}
