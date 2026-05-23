// Реализация интерфейса IFormattable
public string ToString(string format, IFormatProvider formatProvider)
{
    // Если формат пустой, возвращаем число как есть
    if (string.IsNullOrEmpty(format)) return _value;

    int width = 0;
    int precision = -1; // -1 означает, что точность не задана

    // Разделяем строку формата по точке (например, "8.5")
    string[] formatParts = format.Split('.');

    if (formatParts.Length == 2)
    {
        int.TryParse(formatParts[0], out width);      // Первая часть - общая ширина
        int.TryParse(formatParts[1], out precision);  // Вторая часть - знаки после запятой
    }
    else if (formatParts.Length == 1 && !format.StartsWith("."))
    {
        int.TryParse(formatParts[0], out width);      // Если ввели одно число без точки (например, "8")
    }

    // Разделяем наше текущее ВОСЬМЕРИЧНОЕ значение на целую и дробную части
    string[] numberParts = _value.Split('.', ',');
    string intPart = numberParts[0];
    string fracPart = numberParts.Length > 1 ? numberParts[1] : "";

    // 1. ПРИМЕНЯЕМ ТОЧНОСТЬ (работаем с дробной частью)
    if (precision >= 0)
    {
        if (fracPart.Length < precision)
        {
            // Если знаков меньше, чем нужно — дописываем нули справа
            fracPart = fracPart.PadRight(precision, '0');
        }
        else if (fracPart.Length > precision)
        {
            // Если знаков больше — просто отсекаем лишнее (округление для строк)
            fracPart = fracPart.Substring(0, precision);
        }
    }

    // Собираем число обратно
    string formatted = intPart;
    if (!string.IsNullOrEmpty(fracPart) || (precision > 0))
    {
        formatted += "." + fracPart;
    }

    // 2. ПРИМЕНЯЕМ ШИРИНУ (работаем со всей строкой)
    if (width > formatted.Length)
    {
        // Дозируем пробелы слева, чтобы общая длина строки стала равной width
        formatted = formatted.PadLeft(width, ' ');
    }

    return formatted;
}

// Стандартный перегруженный метод (обязателен для Console.WriteLine(num))
public override string ToString()
{
    return ToString(null, null);
}
