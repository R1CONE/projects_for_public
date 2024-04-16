<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Email Form</title>
</head>
<body>
    <form id="emailForm"> 
        <label for="email">Email Address:</label><br>
        <input type="email" id="email" name="email"><br>

        <label for="subject">Subject:</label><br>
        <input type="text" id="subject" name="subject"><br>

        <label for="message">Message:</label><br>
        <textarea id="message" name="message" rows="4" cols="50"></textarea><br>

        <input type="submit" value="Submit">
    </form>
    
    <script>

user_email = 'mikhailsiruts22@gmail.com'
user_password = 

        document.getElementById('emailForm').addEventListener('submit', function(event) {
            event.preventDefault(); 
            
           
            var email = document.getElementById('email').value;
            var subject = document.getElementById('subject').value;
            var message = document.getElementById('message').value;
            
            // Do something with the data (for demonstration, just log it)
            console.log('Email:', email);
            console.log('Subject:', subject);
            console.log('Message:', message);
        });


const nodemailer = require('nodemailer');

// Создаем объект транспорта для отправки сообщений
const transporter = nodemailer.createTransport({
  service: 'Gmail', // Используем сервис Gmail
  auth: {
    
    user: user_email, // Ваша почта
    pass: 'Mikhail123123' // Ваш пароль
  }
});


const mailOptions = {
  from: user_email, // От кого
  to: email, // Кому
  subject: subject,
  text: message
};

// Отправка письма
transporter.sendMail(mailOptions, (error, info) => {
  if (error) {
    console.log('Ошибка при отправке письма:', error);
  } else {
    console.log('Письмо успешно отправлено:', info.response);
  }
});
    </script>
</body>
</html>
