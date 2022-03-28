# Введение
В наше временя оборот информации в бизнес сфере огромен, отцифрованно практически всё. Большая часть информации передаётся по средствам компьютерных сетей, в частности глобальнай – Интернет.

Технология Интернет приспособленна для передачи любого вида закодированной информации, чем пользуется в преимуществе большая часть бизнес отраслей для получения своей прибыли. Но во время развития Интернет появилась такая ниша как Взломщики, люди посягающии на не санкционированное получения доступа к ресурсам подключенных к Интернет. Вследствии начали стремительно развиваться технологии Криптографии , которые существующие еще со времён древнего Рима, и других методов борьбы с Взломщиками и не только.

Взломищакам могут быть интересны любые ресурсы: журналы Бухгалтерии, системы управления предприятеим и т.д.

Подходя к теме о ведении бизнеса в сфере ЧОП многие подозрительные личности могут быть заинтересованн в получении запланированных маршрутов инкосации, адресса жительства сотрудников…
Для пресечения перечисленных выше махинаций можно полностью отказаться от ведения своей деятельности в Интернет. 

Если это не выход – тогда необходимо развертывание системы защиты, чем мы и займемся в пределах данной работы.
Также самым современным решением будет использование Blockchain – децентрализованный метод хранения данных, но данный вариант не будет рассматриваться, так как всё сильно усложняет и, скорее всего, по просту не приемлем.

Решение будет выполненно в несколько шагов:

1. Анализ структуры ЧОП.
2. Анализ проходимых процессов в ЧОП.
3. Описание средств разработки.
4. Составление базы данных ЧОП.
5. Разработка архитектуры приложения для взаимодействия с ЧОП.
6. Реализация архитектурных решений
7. Тестирование.

# Теоритическая часть

## Организация ЧОП
Охранное предприятие занимается охраной какой либо частной или государственной собственности.

ЧОП, чаще всего состоит из трех подразделений:

- Бухгалтерия
- Дирекция(она же администрация)
- Отдел кадров
- Отдел охраны
- Отдел инкосации
- Отдел вооружения

Если говорить о предоствляемых услугах более конкретно, то ЧОП для потребителя предлогает:

- Охрана объекта
- Охрана ценных бумаг или металов(инкосация)

## Информационные потоки ЧОП
![inside info flows](img/infoFlow.png)

## Активности внутри ЧОП
![PSC Activities](img/insideProcess.png)

# Описание средстд разработки
В данном разделе будут рассмотрены средства разработки, используемые мной при создании ПС для ЧОП.

## Утилиты для разработки баз данных

### SQLite v3.35.5 stable
![SQLite logo](https://media.charlesleifer.com/blog/photos/sqlite-logo.png)
SQLite — компактная встраиваемая СУБД. Исходный код библиотеки передан в общественное достояние.
Данная СУБД работает в безсерверной конфигурации. Если сравнивать с другими СУБД, то в равных условиях запись SQLite осуществляет медленее на 20-30% чем другие СУБД, но чтение превосходит другие на 40-50%. SQLite не имеет привелегий, только систему авторизации, но это и не нужно в моем проекте, об этом будет сказано позже.
> Примичание:
> *Библиотека SQLite не будет использована в чистом виде, а в составе Qt v6.2.4*
### SQLiteBrowser v3.12.2
![SQLite Browser](https://sqlitebrowser.org/images/sqlitebrowser.svg)
Удобный FOSS браузер баз данных SQLite, использованный для отладки.
### DBVisualizer v12.1.8
![dbvis](https://www.kessler.de/i/dbvissplash.png)
Проприетарная утилита для работы с разными СУБД, использован для генерации графа таблиц составленной базы данных ЧОП.

## Библиотеки

### Qt v6.2.4
![Qt logo](https://www.qt.io/hubfs/qt-design-system/assets/logos/qt-logo.svg)
Qt - один из самых популярных и больших фреймворков c++ на рынке. Важная характеристика Qt - переносимость, т.к. я работаю на Linux.
## Системы сборки и компиляторы

### CMake v3.22.3
![CMake logo](https://cmake.org/wp-content/uploads/2019/05/Cmake-logo-header.png)
Система сборки c++. Сборка проекта и передача более низкоуровневому средству.
### Ninja c1.10.2
Еще одна система сборки, только уже более низкого уровня, чем CMake. Передача исходного кода на компиляцию.
### clang v13.0.1
Компилятор семейства C. Без коментариев.

## IDE

### QtCreator v6.0.2
![QtCreator logo](https://www.qt.io/hubfs/_website/QtV2/logo_QC.png)
IDE от компинии The Qt Company, использованный только как средство отладки и создания скелетов форм пользовательского интерфейса.
### VIM v8.2
![VIM logo](https://www.vim.org/images/vim_header.gif)
Моя любимая IDE, в своей основе так же прост как и каноничный "блокнот" в Windows, только с максимальной степенью кастомизации. Главное достоинство, по моему мнению, - это управление без использования мыши и возможность настройки управляющих комбинаций максимально удобно, что сокращает время на бесполезное перемещение рук по рабочему пространству.
#### Плагины
```vim
    Plug 'https://github.com/xolox/vim-misc'                   " auto load
    Plug 'https://github.com/xolox/vim-session'                " session manager
    Plug 'wakatime/vim-wakatime'                               " wakatime.com
    Plug 'SirVer/ultisnips'                                    " snippets
    Plug 'https://github.com/honza/vim-snippets'               " snippents files
    Plug 'https://github.com/pangloss/vim-javascript.git'      " javascript extension
    Plug 'vim-airline/vim-airline'                             " status line
    Plug 'vim-airline/vim-airline-themes'                      " themes
    Plug 'vim-scripts/AfterColors.vim'                         " themes
    Plug 'rafi/awesome-vim-colorschemes'                       " themes
    Plug 'sonph/onehalf', { 'rtp': 'vim' }                     " theme
    Plug 'https://github.com/sjl/badwolf'                      " theme
    Plug 'https://github.com/joshdick/onedark.vim'             " theme
    Plug 'https://github.com/plasticboy/vim-markdown'          " markdown format support
    Plug 'ryanoasis/vim-devicons'                              " icons support
    Plug 'https://github.com/Yggdroot/indentLine'
    Plug 'ycm-core/YouCompleteMe'                              " code completer
    Plug 'rdnetto/YCM-Generator', { 'branch': 'stable'}
    Plug 'tpope/vim-commentary'                                " commentary shortcuts
    Plug 'm-pilia/vim-pkgbuild'                                " archlinux AUR PKGBUILD files support
    Plug 'https://github.com/tpope/vim-surround'               " html-like tags handle utils
    Plug 'https://github.com/octol/vim-cpp-enhanced-highlight' " cpp syntax hilightinght
    Plug 'ctrlpvim/ctrlp.vim'                                  " file finder
    Plug 'preservim/nerdtree'                                  " dir tree dock
    Plug 'https://github.com/preservim/tagbar'
    Plug 'vim-scripts/bufkill.vim'                             " exit buffers without exiting vim
    Plug 'jreybert/vimagit'                                    " git support
    Plug 'https://github.com/ap/vim-css-color'                 " HEX-colors hilighting
    Plug 'https://github.com/matze/vim-move'                   " code moving
    Plug 'https://github.com/junegunn/vim-easy-align'          " fast text aligning
    Plug 'https://github.com/ervandew/supertab'
    Plug 'https://github.com/jiangmiao/auto-pairs'             " completing pairs
    Plug 'https://github.com/rhysd/vim-clang-format'           " auto formating
    Plug 'honza/vim-snippets'                                  " set of snippets
    Plug 'https://github.com/godlygeek/tabular'                " tab extender
    Plug 'https://github.com/junegunn/vim-easy-align'
    Plug 'https://github.com/fadein/vim-FIGlet'  " figlet
    Plug 'https://github.com/scrooloose/syntastic'
```

## Разное

### Plantuml v1.2021.16
![plantuml](https://plantuml.com/logo3.png)
Средство создания UML диаграм. Использовано для визуализации объектов и просецссов.
### BASH v5.1.16
![bash](https://www.pngfind.com/pngs/m/261-2614514_bash-logo-shell-script-logo-png-transparent-png.png)
Bourne Again Shell - интерпритатор, использован для автоматизации некотерых процессов.
> Примечание:
> Оглавления данной работы было автоматически сгенерерованно данным bash-скриптом:
```bash
cat "$1" > "$1".indexed

>index

i=(-1 1)
prevLen=0
while read -r line; do
    hash="$(md5sum <<< "$line" | cut -d ' ' -f 1)"
    printf "<a id=\"%s\"></a>\n%s\n" "$hash" "$line" > tmp
    sed "/$line/ {
        x
        r /home/xewii/Documents/TIT/ZXC/tmp
    }" "$1".indexed > "$1".indexed.tmp
    mv "$1".indexed.tmp "$1".indexed
    hdrLen=$(awk -F'#' '{print NF-1}' <<< "$line")
    hdrTxt=$(echo "${line//#/}")
    (( $hdrLen > 1 )) && for (( j=1; j<$hdrLen*4; j++ )); do printf ' '; done
    (( $prevLen < $hdrLen )) && i[$hdrLen]=1
    printf "%d.[%s](#%s)\n" ${i[$hdrLen]} "$hdrTxt" "$hash"
    prevLen=$hdrLen
    let i[$hdrLen]++
done <<< "$(grep --color=no -E "^#+" "$1")" > index

mv "$1".indexed tmp
printf "# Содержание\n" > "$1".indexed
cat index >> "$1".indexed
cat tmp >> "$1".indexed

rm tmp
rm index

```

## Отладка

### Valgrind v3.18
Утилита профилирования и отладки программы, использовано в основном для обнаружения утечек памяти.
## VCS

### GIT v2.35.1
GIT - система контроля версий, сомо о себе говрит. Использовался в основном для перенесения кода между машинами и как средство дистрибъюции.

# Разработы базы данных ЧОП
База данных ЧОП в пределах данной работы - головная сущность, вокрук которой будет строится весь функционал.
База данных будет существовать под управлением SQLite.

## Таблицы
В компанию, как известно, входит некоторое количество сотрудников, по этому, я создаю таблицу Users. Название выбрано таковым, потому что она будет содержать данные учетных записей сотрудников и клиентов ЧОП.
```sql
CREATE TABLE
    "Users"("id" INTEGER NOT NULL UNIQUE,
            "name" TEXT NOT NULL,
            "entryDate" TEXT NOT NULL,
            "role_id" INTEGER NOT NULL,
            "wapon_id" INTEGER,
            "email" TEXT UNIQUE,
            "login" TEXT NOT NULL UNIQUE,
            "password" BLOB NOT NULL UNIQUE,
            "salt" BLOB NOT NULL,
            "image" BLOB,
            FOREIGN KEY("wapon_id") REFERENCES "Wapons"("id")ON DELETE RESTRICT,
            FOREIGN KEY("role_id") REFERENCES "Roles"("id")ON DELETE RESTRICT,
            PRIMARY KEY("id" AUTOINCREMENT))
```
Таблица содержит данные для идентификации:

- login
- password
- salt

Пароль не храниться в открытов виде, а зашифорован с использованием динамической соли по алгоритму "Prefered salt algorithm", более подробно будет расмотрен далее.

Как видно, таблица Users зависит от таблиц Roles и Wapons, собственно вот они:
```sql
CREATE TABLE
    "Roles"("id" INTEGER NOT NULL UNIQUE,
        "name" TEXT NOT NULL UNIQUE,
                "commands_id" INTEGER NOT NULL,
                "payMultipler" DECIMAL(10, 3) NOT NULL,
                "payPeriod" INTEGER NOT NULL,
                FOREIGN KEY("commands_id") REFERENCES
                "roleCommands"("role_id")ON DELETE RESTRICT,
                PRIMARY KEY("id"))
```
Роль определяет какие данные и соответственно команды можешь выполнять на сервере. Ссылается на таблицу roleComands - это SQL массив с ID команд, которые может выполнять пользователь с данной ролью, по поэтому я и отказался от других, более тяжелых СУБД, т.к. все необходимые действия делегируются на Сервер, что будет рассмотрено далее, от СУБД требуется только хранить данные и извлекать их.
Связаная таблица roleCommands:
```sql
CREATE TABLE
    "roleCommands"("role_id" INTEGER NOT NULL,
                   "command_id" INTEGER NOT NULL,
                   FOREIGN KEY("role_id") REFERENCES
                   "Roles"("id")ON DELETE RESTRICT)
```
Таблица Wapons:
```sql
CREATE TABLE
    "Wapons"("id" INTEGER NOT NULL UNIQUE,
                 "employee_id" INTEGER UNIQUE,
                 "name" TEXT NOT NULL,
                 "ammo" INTEGER NOT NULL,
                 "price" DECIMAL(10, 3) NOT NULL,
                 "ammoPrice" DECIMAL(10, 3) NOT NULL,
                 "image" BLOB,
                 FOREIGN KEY("employee_id") REFERENCES
                 "Users"("id")ON DELETE RESTRICT,
                 PRIMARY KEY("id"))
```
Каждая запись в таблице Wapons - это еденица зарегестрированного оружия, в полной мере описывающяя необходимые характеристики для ЧОП.

Так как организация имеет свои расходы и доходы, нам нужно сохранять эти данные.
Таблица Accounting:
```sql
CREATE TABLE 
    "Accounting" ("id" INTEGER NOT NULL UNIQUE,
              "accountingType_id" INTEGER NOT NULL,
              "pay" DECIMAL(10, 3) NOT NULL,
              "date" TEXT NOT NULL,
              FOREIGN KEY("accountingType_id")
              REFERENCES "AccountingType"("id") ON DELETE RESTRICT,
              PRIMARY KEY("id") )
```
Зависит от таблицы AccountingType, описывающей какого рода транзакция была совершена.
```sql
CREATE TABLE
    "AccountingType" ("id" INTEGER NOT NULL UNIQUE,
                  "name" TEXT NOT NULL UNIQUE,
                  PRIMARY KEY("id","name") )
```

ЧОП получает доход от контрактов, по этому была составлена таблица Contracts:
```sql
CREATE TABLE
    "Contracts"("id" INTEGER NOT NULL UNIQUE,
                "assignedEmployees_id" INTEGER NOT NULL,
                "customer_id" INTEGER NOT NULL,
                "objectType_id" INTEGER NOT NULL,
                "objectAddress" TEXT NOT NULL,
                "objectWayPoint" TEXT, "date" TEXT NOT NULL,
                "expirationDate" TEXT NOT NULL,
                "weekends" TEXT NOT NULL,
                FOREIGN KEY("customer_id") REFERENCES
                "Users"("id")ON DELETE RESTRICT,
                PRIMARY KEY("id"),
                FOREIGN KEY("assignedEmployees_id") REFERENCES
                "AssignedEmployees"("employee_id") ON DELETE RESTRICT,
                FOREIGN KEY("objectType_id") REFERENCES
                "objectType"("id")ON DELETE RESTRICT)
```
Запись в таблице Contracts это сделка вида, описанного в связаной таблице objetType.
Таблица objetType:
```sql
CREATE TABLE
    "objectType" ( "id" INTEGER NOT NULL UNIQUE,
                   "name" TEXT NOT NULL UNIQUE,
                   "price" DECIMAL(10, 3) NOT NULL,
                   PRIMARY KEY("id") )
```
Запись в данной таблице описывает объект контракта, где указывается базавая цена за период оплаты(payPeriod) исполнителя/исполнителей контракта(assignedEmployees_id).
Для привязки нескольких сотрудников, была создана еще одна таблица AssignedEmployees, являющейся массивом.
```sql
CREATE TABLE
    "AssignedEmployees" ( "id" INTEGER NOT NULL,
                          "employee_id" INTEGER NOT NULL,
                          "guiltyPercent" DECIMAL(10, 3) NOT NULL,
                          "usedAmmo" INTEGER,
                          FOREIGN KEY("employee_id") REFERENCES
                          "Users"("id") ON DELETE RESTRICT,
                          PRIMARY KEY("id") )
```
Для создания контракта в данной таблице нужно только 2 поля - id, employee_id.
Так так во время исполнения может произойти какой то ицедент, то была создана таблица Accidents:
```sql
CREATE TABLE
    "Accidents" ("id" INTEGER NOT NULL UNIQUE,
             "name" TEXT NOT NULL,
             "contract_id"
             INTEGER NOT NULL,
             "usedAmmoCount" INTEGER,
             "damagePrice" DECIMAL(10, 3),
             "assignedEmployees_id" INTEGER,
             FOREIGN KEY("contract_id") REFERENCES "Contracts"("id") ON DELETE RESTRICT,
             FOREIGN KEY("assignedEmployees_id") REFERENCES "AssignedEmployees"("id") ON DELETE RESTRICT,
             PRIMARY KEY("id") )
```
Описывает проишествия, произошедшие во время исполнения контракта.
Если у нас есть контракты, описывающие некую деятельность с учетом выходных и рамок начала и окончания службы, то можно было бы ускорить вычисление рабочего времени по дням с помощью препроцессинга данных из записи Contracts. Таблицей, в которую сохраняются транслированные данные является - DutySchedule:
```sql
CREATE TABLE
    "DutySchedule" ( "emploee_id" INTEGER NOT NULL,
                     "day" INTEGER NOT NULL
                     FOREIGN KEY("emploee_id") REFERENCES "Users"("id") ON DELETE RESTRICT )
```
day - это 64х битная цыфра со знаком в формате UNIX time(secs since epoch). 

## Визуализация базы данных
![Datbase visualization](/home/xewii/Documents/TIT/ZXC/databaseReferences.png)

# Разработка архитектуры приложения
Приложение для взаимодействия с моделью ЧОП, построенной ранее, должно предоставлять функционал для реализации всех описанных процессов взаимодействия с моделью ЧОП.

## Основа
Основной функцией приложения, как понятно из темы курсовой работы, будет обеспечение безопасности данных.
Исходя из этого в голову приходит идея организовать клиент-серверную архитектуру приложения, но это не главная причина почему выбрана такая архитектура. Основная причина - необходимость принимать заказы от клиентов, предоставить им функционал для удобного взаимодействия с персоналом ЧОП, но по большей части он будет взаимодействовать с клавиатурой.
И для персонала ЧОП тоже будет намного удобнее и быстрее использовать унифицированные методы итерации с базой данных и самой организацией.

### Информационные потоки ЧОП с учетом сервера
![PSC with server info flows](/home/xewii/Documents/TIT/ZXC/infoServiceFlow.png)

## Обращение к базе данных
Как было сказано ранее, СУБД не будет управлять системой привелегий, этим будет заниматься другой код. Система, которую я разработал основана на ролях, так же как и в обычных "умных" СУБД, к которым привязано некоторое количество возможных к исполнению команд.
![](img/identificationSystem.png)

### Система безопасности
Для обеспечения более высокого уровня защиты команды и роли будут вшиты в программу. При каждом старте будет проверятся валидность первоначальных данных и имеющихся на данный момент в базе данных.
Также, как мера безопасности к ПС будут предложены хеш суммы исполняемых файлов. 
#### Система идентификации и авторизации
При регистрации нового пользователя создается новая запись в таблице Users, все поля, короме поля password сохраняются в неизменнов виде. password сохраняется в захешированном виде при использовании хэш функции sha512 с использование динамической соли.

Алгоритм создания соли:

1. Подсчет количества символов разных типов в пароле.
2. Выявление слабых сторон пароля.
3. Формирование алфавита для создания соли.
4. С помощью "strog random" функции выборка символов из составленого алфавита.
5. Запись результата.

Алгоритм хэширования пароля:

1. Генерация соли.
2. Взятие первичного хеша с пароля.
3. Итерационно выбрать по байтно методом XOR младших битов первичного хеша и переданного пароля места вставки соли.
4. Хеширование получившейся строки.
5. Запись результата.

Данный алгорит и выбраная хэш функция ограничивают максимальную длину пароля до 64 символов.
Длина соли была вабрана 32 байтная.
Соль сохраняется вместе с паролем, чтобы обеспечить возможность идентификации.

Для идентификации проводится сравнивание значение пароля из базы данных с переданным в функцию шифрования с солью данной записи пользователя пароля.

#### Система команд
Проанализировав информационные потоки и требования ЧОП я составил 22 команды, в исходном коде объявление команд выглядит вот так:

```C
// id, name, executor
#define COMMANDS_MAP(XX) \
    XX( 0,  MAKE_CONTRACT,        exec_make_contract      ) \
    XX( 1,  MAKE_DUTY_SCHEDULE,   exec_make_duty_schedule ) \
    XX( 2,  REGISTER_ACCIDENT,    exec_register_accident  ) \
    XX( 3,  REGISTER_EMPLOYEE,    exec_register_employee  ) \
    XX( 4,  REGISTER_CUSTOMER,    exec_register_customer  ) \
    XX( 5,  REGISTER_OBJECT_TYPE, exec_register_object_type) \
    XX( 6,  REGISTER_WAPON,       exec_register_wapon     ) \
    XX( 7,  ASSIGN_WAPON,         exec_assign_wapon       ) \
    XX( 8,  PAY_AMMO,             exec_pay_ammo           ) \
    XX( 9,  PAY_EMPLOYEE,         exec_pay_employee       ) \
    XX( 10, PAY_ACCIDENT,         exec_pay_accident       ) \
    XX( 11, EDIT_OBJECT_TYPE,     exec_edit_object_type   ) \
    XX( 12, UPDATE_ROLE,          exec_update_role        ) \
    XX( 13, GET_USER_INFO,        exec_get_user_info      ) \
    XX( 14, GET_ACCIDENT_DETAILS, exec_get_accident_details) \
    XX( 15, GET_ACCOUNTING_ENTRY, exec_get_accounting_entry) \
    XX( 16, GET_OBJECT_DETAILS,   exec_get_object_detalils) \
    XX( 17, GET_ROLE_DETAILS,     exec_get_role_details   ) \
    XX( 18, GET_WAPON_DETAILS,    exec_get_wapon_details  ) \
    XX( 19, GET_DUTY_SCHEDULE,    exec_get_duty_schedule  ) \
    XX( 20, CREATE_TABLE,         exec_create_table       ) \
    XX( 21, IDENTIFY,             exec_identify           ) \
```

## Архитектура Клиент-Сервер
Архитектура Клиен-Сервер была выбрана не только для обеспечения безопасности базы данных, но и для реализвации удаленного унифицированного доступа к услугам и возможностям ЧОП.
Так для сотрудников упрощается способ комуникации с начальством, подчиненными. А заказчики смогут после регистрации в системе могут удаленно составить контракт по охране.

### Протокол
Общение клиентов с сервером будет осуществяться по протоколу TCP опиционально с использованием SSL/TLS(опциональность введена для более удобного тестирования).

#### Формат сообщений
Поверх формата TCP пакета я ввел для ПС дополнительные поля.

Состоит из заголовка и нагрузки.

*Заголовок*
Длина заголовка - 176 бит или 22 байта. Кончно, можно было бы спокойно использовать все 192 бита(3 машинных слова), чтобы выравнять заголовок, но это не сильно повлияет на какой либо процесс.
Поля:

(занимаемые байты в сообщении) Имя: Описание

- (0x0  - 0x3)  Size: суммарный размер сообщения в байтах
- (0x4  - 0x11) ServerStamp: Время отправки сообщения сервером
- (0x12 - 0x19) ClientStamp: Время отправки сообщения клиентом
- (0x20 - 0x21) PacketType: Тип сообщения
- (0x22 - 0x23) PacketLoadType: Тип формата нагрузки сообщения

Таким образом, поле Size позволяет считывать последовательность байт в единое сообщение из нескольких пакетов TCP.
Поля xxxStamp используются как некий идентификатор сообщения.
Тип пакета и формат нагрузки определяют собственно тип нагрузки и сообщения в целом.

### Модель сервера
Основные задачи сервера:

- обслуживании базы данных
- реализации механизма идентификации и авторизации, также регистрации
- принятие входящих запросов на подключение
- работа в режиме Запрос => Ответ
- Мониторин протекающих процессов

Также, развертывание сервера будет означать создание первого Amin пользователя, для управления организационными процессами ЧОП. Следовательно у сервера должен быть интерфейс для создания пользователей, как и у клиента.

![Server abstract model](img/serverStruct.png)

### Модель клиента
Клиент - это программа, предоставляющая некотерый функционал, в который в любом случае входит пользовательский интерфейс, после успешного входа в систему, функционал будет разниться в зависимости от роли вошедшего в систему.

Все что требуется от клиента - это показывать пользовательский интерфейс, предоставить некотерый метод для входа в систему сервера и отправлять команды серверу, и ждать ответа.
В частности, когда пользватель, который воспользовался клиентом является заказчик - клиент должен предоставить метод регистрации в систему.

![Client abstract mode](img/clientStruct.png)

# Реализация
Для реализации проекта был выбран язык C++ и фреймвокр Qt6. Выбор лег в сторону C++ только потому что это мной наиболее изученный язык, на много проще было бо всё реализовать на nodejs с express, а Qt - это лучшый кросплатформенный фреймворк лично для меня, он упростил разработку процентов на 60% и сократил зависимости проекта на 100%(используются только библиотеки из пакета Qt).
Сборкой проекта будет заниматься CMake с делегацией компиляции Ninja, C++ компилятор - clang.
Для отладки буду использовать GDB в составе QtCreator и Valgrind.
Создания шаблонов форм так же будет осуществляться в QtCreator в модуле QtDisigner.

## Пользовательский интерфейс
За отрисовку GUI будет отвечать модуль Qt - QtGUI.

Пользовательский интерфейс будут составлять 5 основных сущностей:

- Бар состояния
- Меню бар
- Тул бар
- Пейджер(PagesManager)
- Менеджер уведомлений(NotifyManager)

### PagesManager
TODO

### NotifyManager
TODO

## Драйвер базы данных

## iiServer

# Заключение
TODO

# Список литиратуры
1. https://wiki.qt.io - документация Qt
2. https://www.sqlite.org/ - документация SQLite
