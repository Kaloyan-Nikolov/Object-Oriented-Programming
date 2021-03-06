Темата на проекта е: Работа със SVG файлове

Проектът е разработен с Microsoft Visual Studio 2017.

Основни класове:

Първият клас в програмата е класът Point, който представя точката като обект с две член-данни – координати x и у (цели числа).

Класът BasicShape е абстрактен и се използва като интерфейс от класовете Rect, Circle и Line, които го наследяват.

Класът Rect представя правоъгълник чрез точката, която е негов горен ляв ъгъл, ширина, височина и цвят.

Класът Circle представя кръг чрез точката, която е негов център, радиуса на кръга и цвят.

Класът Line представя линия като 2 точки, дебелина на линията и цвят.

Класът StringCheck обединява различни функции за проверка или работа със символни низове.

Класът ReadFromFile обединява функции, които се използват за осъществяването на операцията четене от файл.

Класът Factory се използва за създаване на нови обекти.

Класът ShapeContainer съдържа вектор от различни фигури. В него са реализирани функции, които добавят нова фигура, изтриват фигура, транслират 1 или всички фигури, принтират всички фигури и други. Реализиран е като singleton.

Класът Commands реализира всички функции, необходими за работата на програмата.

Чужд код:

За написването на проекта не съм копирал код от други източници. Използвал съм std::string и std::vector.

Начин, по който съм реализирал някои команди:

При въвеждане от конзолата, числата x, -x, +x се разглеждат като x. Изключение прави функцията translate, при която vertical=-10 horizontal=-20 се прочита като -10 и -20. В противен случай веднъж транслирани фигурите няма да могат да се върнат в изходната си позиция. Когато се извика командата > translate vertical=-10 horizontal=-20 тя се изпълнява само от тези фигури, които ще останат напълно видими след транслация(всичките им точки остават с положителни координати).

create: изисква името на фигурата и съответните параметри. Прави се проверка дали фигурата с тези параметри ще бъде видима и дали не съвпада с точка (за линия и кръг) и с точка или линия (за правоъгълник). Ако потребителя не въведе цвят или въведе грешен цвят (число или символен низ) програмата дава син цвят на фигурата. Като възможни цветове съм използвал главните от: https://www.december.com/html/spec/colorsvg.html

print: извежда на екрана всички фигури, ако има такива

erase: изтрива фигура по даден индекс (ако съществува)

translate: транслира 1 или всички фигури, ако съответните фигури ще останат видими.

within: изисква да се напише circle или rectangle и след това съответните параметри на фигурата. Принтира фигурите, които се намират в зададения кръг или правоъгълник.

open: прави опит да се отвори файла с даденото име. Програмата не изисква да се напише разширение на файла, тъй като .svg се добавя автоматично. (Важи и за команда saveas) Ако няма такъв се създава нов файл (ако директорията и името на файла са правилни). Като се отвори файл се намира информацията за наличните фигури (правоъгълници, линии и кръгове) и информацията за всяка от тях се записва като string във вектор от стрингове. След това с информацията от всеки елемент от вектора се прави опит да се създаде обект. (правят се същите проверки като при командата create).

Реализирани са и функциите: close, save, saveas, exit, help.

Структурирал съм кода по начин, по който добавянето на още фигури в приложение да изисква минимален брой промени.
