# cpp-unicode
This repo is just a playground to work on unicode support for C++(20) projects.

On Linux, looks like you can just use a simple char to hold a unicode character
and it will work.

On Windows in the other hand, you need to do some sorcery to get this working.

## Notes
On Linux, if you want to use the hex value for a unicode character you need to
use the escape sequence `\u` before the string literal. You can also use the
character itself in the string literal if you encode your file in utf-8.

```cpp
std::cout << "\u2502" << "\n";
std::cout << "│" << "\n";
```

This will print a vertical line called _"Box Drawings Light Vertical"_.

On Windows, besides not being able to print to stdout using simple `std::cout`,
you need to use the escape sequence `\x` to input the hex code of the character
and especify that you want to treat it as a wide character using an `L` prefix.
This would be in UTF-8 encoding. You may also be able to use a prefix `u` for
UTF-16 or `U` for UTF-32.

```cpp
fflush(stdout);
_setmode(_fileno(stdout), _O_U16TEXT);
std::wcout << L'\x2502' << "\n";
```

Use this wiki for reference:
[MSDN](https://docs.microsoft.com/en-us/cpp/cpp/string-and-character-literals-cpp?view=msvc-170)
