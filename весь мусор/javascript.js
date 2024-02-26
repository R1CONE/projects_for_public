<script src="main.js"></script>
var num;

num = 7;

console.log(num)

document.write("Переменная:" + num + ".");

var number; 

number = "Words";

var bool, bool2;

bool = true;

bool2 = "2";

var n1 = 5;

var n2 = 10;

var n3;

n3 = n2 + n1;

document.write("Переменная:" + n3);

document.write("Переменная2: " + (n2 - n1));

num_rand = Math.random(1, 10);
document.write(num_rand);

var number = 15;

if (number == 0 && numbers == 11){
    console.log('true');
}
else if(number == 15){
    console.log('true');

}
else {
    console.log('false');
}

if (number == 2 || bool == true) {

} else {

}

var strok = 'work';

switch (strok) {
    case "4": console.log('Переменная со значением 4');

        break;

    case "5": console.log('Переменная со значением 5');

        break;

}

console.log("Math: " + Math.max(4, 67, -1, 0, -11))
console.log("Math: " + Math.min(4, 67, -1, 0, -11))

var stroka = 'some text';

switch(stroka){
	case "4":
	comnsole.log('Значение с переменной 4');
	break;
	case "some text":
	comnsole.log('some text');
	break;
} 

console.log(arr.length);

var matrix = [
	[4, 2, 1], ["lol", 'text', '5.1'], [0, 100]
];

matrix[1][0] = 90; //замена первого элемента во втором массиве в матрице 

for(var i = 0; i < 10; i++){
	console.log(i)
}

var j = 0;
while(j < 10){
	console.log(j);
	j++;
}
//////////

x = 100;
do{
	console.log('Text');
} while(x < 50);

for(var i = 10; i <= 20; i++){
	if(i % 2 == 0)
	continue;
	console.log(i);
}
////////
alert("какая хорошая погода!");

var data = confirm("Вы сейчас дома?");

if(data = True) {
	alert("Вы солодец!");
}

var data = prompt("Сколько тебе лет");
console.log(data);

var var1 = null;
////

var person = null;
if(consirm("Вы точно уверенны?")){
	person = promt("Введите ваше имя");
	alert("привет, " + person);
}	
else {
	alert("Вы нажали на отмена");
}

////

ion info(word){
	console.log(word);
}

info("hello");
//

function info(word){
	console.log(word);
}

info("hello");

function summa(a, b){
	var res = a + b;
	console.log(res);
}
summa(5, 7);
///
ПОДСЧЕТ КОЛЛИЧЕСВА ЭЛЕМЕНТОВ В ЛИСТЕ

function(arr){
	var sum = 0;
	for(var i = 0; i < arr.length; i++)
		sum += arr[i];

	return sum;

}

var array = [6, 8, 1];

var res = summa(array);

//
<button onclick = "alert('Button has touched')"> Нажми на меня</button> 
////
<button onclick = "onClickButton()"> Нажми на меня</button>

function onClickButton(){
	alert('You pressed button');
}
///
<button onclick = "onClickButton()"> click me</button>

var counter = 0;

function onClickButton(){
	counter++;
	console.log(counter);
}
///
var counter = 0;

function onClickButton(el){
	counter++;
	el.innerHTML = ('click me' + counter);
}
///
<input oninput = "onInput(this)">

function OnInput(el){
	console.log(el.value);
}
///
<p id = "text">Text</p> 
var text = document.getElementById('text');
alert(text);
//
<body>
    <form id="main-form" onsubmit="return checkForm(this)" method = "post">
        <label for="name">name: </label>
        <input type="text" name="name" placeholder="Имя">

        <label for="surname">lastname: </label>
        <input type="text" name="surname" placeholder="Фамилия">

        <label for="height">height: </label>
        <input type="text" name="height" placeholder="Рост">

        <button type="sumbit" name="sumbit">Ready</button>
    </form>
</body> 
function checkForm(el){
	var name = el.name.value;
	console.log(name);
	return false;
	//all correct 
	
	if (name = ""){
		fail = "Enter all";
	}
	else{
	alert('all correct');
	window.location = "https://www.twitch.tv/serega_pirat"

	}
}
/////

setInterval(my_func, 1000);
var counter = 0;
function my_func(){
	counter++;
	console.log(counter);

}
///
setTimeout(function(){
	console.log("Timer is working");

}, 2000); //2sec for
/////

var date = new Date();

//console.log(date.getFullYear());
//console.log(date.getMounth() + 1);
//console.log(date.getDate());

date.setHours(11);
date.setMinutes(11);

console.log("Time: " + date.getMinutes() + ":" + date.getMinutes());
////

var arr = [0, 1, 2, 3, 4];

console.log(arr.join("||"));     0||1||2||3||4

console.log(arr.sort()); [0, 1, 2, 3, 4]

console.log(arr.reverse()); [4, 3, 2, 1, 0]

var stroka = arr.reverse().join(",");

console.log(stroka.split(","));

///

class Person {
	construktor(name, age){
		this.name = name;
		this.age = age;
	}

	info() {
		console.log("Persone: " + this.name + "Age" + this.age);
	}
}
var alex = new Person("Alex", 133);
var nigga = new Person("Mikel Jordan", 200);
console.log(nigga.age);
console.log(alex.name);

alex.info();
///
for (let i = 0; i < someArray.length; i++) {
    // код, выполняемый внутри цикла
}
////



