
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <title>Конспект jQuery</title>

    <!-- Подключение библиотеки jQuery -->
    <script src="https://code.jquery.com/jquery-3.7.1.min.js"></script>
</head>
<body>

<!--
========================================
       КОНСПЕКТ JQUERY
========================================

1. WYBIERANIE ELEMENTÓW HTML
   Выбор HTML-элементов

   $("p")       - все элементы <p>
   $("#tekst")  - элемент с id="tekst"
   $(".klasa")  - все элементы с class="klasa"
   $("*")       - все элементы страницы
   $("h1, p")   - все h1 и p
   $(this)      - текущий элемент
   $("p:first") - первый элемент p
-->

<h1 id="naglowek">Пример jQuery</h1>
<p class="tekst">Первый параграф</p>
<p class="tekst">Второй параграф</p>

<script>
$(document).ready(function() {

    // Выбор по тегу
    $("p").css("color", "blue");

    // Выбор по ID
    $("#naglowek").css("color", "red");

    // Выбор по классу
    $(".tekst").css("font-size", "20px");

    // $(this) - текущий элемент
    $("p").click(function() {
        $(this).css("color", "green");
    });

});
</script>


<!--
========================================
2. ZDARZENIA (EVENTS)
   События
========================================

click()       - одинарный клик
dblclick()    - двойной клик
mouseenter()  - курсор входит на элемент
mouseleave()  - курсор покидает элемент
mousedown()   - нажата кнопка мыши
mouseup()     - кнопка мыши отпущена
hover()       - наведение и уход курсора
focus()       - поле получает фокус
blur()        - поле теряет фокус
keydown()     - нажата клавиша
keyup()       - клавиша отпущена

Синтаксис:
$("селектор").событие(function() {
    // Код
});
-->

<h2>2. События</h2>

<button id="klik">Click</button>
<button id="dbl">Double Click</button>
<div id="pole" style="padding:20px; background:lightblue;">
    Наведи курсор сюда
</div>
<input id="poleTekstowe" placeholder="Введи текст">

<p id="wynik">Результат появится здесь</p>

<script>
$(document).ready(function() {

    // Одинарный клик
    $("#klik").click(function() {
        $("#wynik").text("Кнопка нажата!");
    });

    // Двойной клик
    $("#dbl").dblclick(function() {
        $("#wynik").text("Двойной клик!");
    });

    // Наведение мыши
    $("#pole").mouseenter(function() {
        $(this).css("background", "yellow");
    });

    // Уход мыши
    $("#pole").mouseleave(function() {
        $(this).css("background", "lightblue");
    });

    // Фокус на поле
    $("#poleTekstowe").focus(function() {
        $(this).css("background", "lightgreen");
    });

    // Потеря фокуса
    $("#poleTekstowe").blur(function() {
        $(this).css("background", "white");
    });

});
</script>


<!--
========================================
3. UKRYCIE I POKAZANIE ELEMENTU
   Скрытие и показ элемента
========================================

hide()   - скрывает элемент
show()   - показывает элемент
toggle() - переключает скрытие/показ

Можно указать скорость:
"slow" - медленно
"fast" - быстро
1000   - 1 секунда

Синтаксис:
$("p").hide();
$("p").show();
$("p").toggle(1000);
-->

<h2>3. Hide / Show</h2>

<p id="ukryty">Этот текст можно скрыть и показать.</p>

<button id="hide">Hide</button>
<button id="show">Show</button>
<button id="toggle">Toggle</button>

<script>
$(document).ready(function() {

    // Скрытие
    $("#hide").click(function() {
        $("#ukryty").hide(500);
    });

    // Показ
    $("#show").click(function() {
        $("#ukryty").show(500);
    });

    // Переключение
    $("#toggle").click(function() {
        $("#ukryty").toggle(500);
    });

});
</script>


<!--
========================================
4. SLIDE DOWN / SLIDE UP
   Плавное появление и скрытие
========================================

slideDown()   - плавно показывает элемент сверху вниз
slideUp()     - плавно скрывает элемент снизу вверх
slideToggle() - переключает оба эффекта

Синтаксис:
$("p").slideDown(500);
$("p").slideUp(500);
$("p").slideToggle(500);

Эти методы работают с видимостью элемента,
плавно изменяя его высоту.
-->

<h2>4. Slide Down / Slide Up</h2>

<button id="down">Slide Down</button>
<button id="up">Slide Up</button>
<button id="slideToggle">Slide Toggle</button>

<div id="panel" style="
    display:none;
    padding:20px;
    background:lightgreen;
    border:1px solid green;">
    Этот блок появляется и скрывается
    с помощью эффекта Slide.
</div>

<script>
$(document).ready(function() {

    // Плавное появление
    $("#down").click(function() {
        $("#panel").slideDown(500);
    });

    // Плавное скрытие
    $("#up").click(function() {
        $("#panel").slideUp(500);
    });

    // Переключение эффектов
    $("#slideToggle").click(function() {
        $("#panel").slideToggle(500);
    });

});
</script>


<!--
========================================
5. NAJWAŻNIEJSZE INFORMACJE
   Самое главное для контрольной
========================================

ВЫБОР ЭЛЕМЕНТОВ:
$("p")       - по тегу
$("#id")     - по ID
$(".class")  - по классу
$(this)      - текущий элемент

СОБЫТИЯ:
.click()       - клик
.dblclick()    - двойной клик
.mouseenter()  - наведение
.mouseleave()  - уход мыши
.focus()       - фокус
.blur()        - потеря фокуса
.keydown()     - нажатие клавиши

СКРЫТИЕ И ПОКАЗ:
.hide()        - скрыть
.show()        - показать
.toggle()      - переключить

АНИМАЦИЯ:
.slideDown()   - показать с эффектом слайда
.slideUp()     - скрыть с эффектом слайда
.slideToggle() - переключить слайд

ВАЖНО:
$(document).ready(function() {
    // Код запускается после готовности DOM
});

Можно использовать короткую запись:
$(function() {
    // Код
});

Пример:
$("button").click(function() {
    $("p").hide();
});

Нажатие на кнопку скроет все параграфы.
========================================
-->

</body>
</html>
