- Enums into scoped enum (see https://hackingcpp.com/cpp/lang/enumerations.html)
- Check constexpr
- Attribute [[nodiscard]] to add ? -> Make the linter more aggresive ?
- Compilers flags (-Wall -Wextra -Wpedantic -Wshadow -Wconversion -Werror -fsanitize=undefined,address -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wformat=2 -Wimport -Winvalid-pch -Wlogical-op -Wmissing-declarations -Wmissing-field-initializers -Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn -Wpacked -Wpointer-arith -Wredundant-decls -Wstack-protector -Wstrict-null-sentinel -Wundef -Wwrite-strings)



- Use shared pointer in vector (Using reference/pointer from vector is bad practice since the vector content can change)
	-> List where (non exhaustive):
	- Near Inprutcontroller pointer from input manager

- For the Controller states, no needs of mutexes since only one writer


- Test the 'bind_player' func
