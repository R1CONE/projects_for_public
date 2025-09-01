package com.example.gdiejava

import android.app.NotificationChannel
import android.app.NotificationManager
import android.content.Context
import android.os.Build
import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.*
import androidx.compose.runtime.Composable
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.core.app.NotificationCompat
import com.example.gdiejava.ui.theme.GdieJavaTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            GdieJavaTheme {
                Scaffold(modifier = Modifier.fillMaxSize()) { innerPadding ->
                    Greeting(
                        name = "Android",
                        modifier = Modifier.padding(innerPadding)
                    )
                }
            }
        }
    }
}

@Composable
fun Greeting(name: String, modifier: Modifier = Modifier) {
    val context = LocalContext.current

    Column(modifier = modifier.padding(16.dp)) {
        Text(text = "Hello $name! Thats my first text")

        OutlinedTextField(
            value = "Default text",
            onValueChange = {}
        )

        // Встраиваем большую красную кнопку
        BigRedButton(context = context)
    }
}

@Composable
fun BigRedButton(context: Context) {
    Button(
        onClick = { showNotification(context) },
        colors = ButtonDefaults.buttonColors(containerColor = Color.Red),
        modifier = Modifier
            .fillMaxWidth()
            .height(80.dp)
            .padding(top = 16.dp)
    ) {
        Text("гойда", color = Color.White, fontSize = 24.sp)
    }
}

fun showNotification(context: Context) {
    val channelId = "my_channel_id"
    val notificationManager =
        context.getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager

    // Создаём канал для Android 8+
    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
        val channel = NotificationChannel(
            channelId,
            "MyChannel",
            NotificationManager.IMPORTANCE_DEFAULT
        )
        notificationManager.createNotificationChannel(channel)
    }

    // Само уведомление
    val notification = NotificationCompat.Builder(context, channelId)
        .setContentTitle("Уведомление")
        .setContentText("Договорнячок")
        .setSmallIcon(android.R.drawable.ic_dialog_info)
        .build()

    notificationManager.notify(1, notification)
}

@Preview(showBackground = true)
@Composable
fun GreetingPreview() {
    GdieJavaTheme {
        Greeting("Android")
    }
}


/////


var counter = remember {
        mutableStateOf(0)
    }
    
    Card(
        modifier = Modifier
            .fillMaxWidth()
            .clickable{
                counter.value++
                Log.d("MyLog", "Item Clicked $counter")
            }
            .padding(10.dp).offset(40.dp), //отступ по вертикали слева
        shape = RoundedCornerShape(15.dp),
        elevation = CardDefaults.cardElevation(5.dp)
    ) {
        Box(modifier = Modifier.background(Color.Green)) {
            Row(
                modifier = Modifier.padding(8.dp),
                verticalAlignment = Alignment.CenterVertically
            ) {
                Image(
                    painter = painterResource(id = R.drawable.durov_insta_grazhdanstvo_2021),
                    contentDescription = "image",
                    contentScale = ContentScale.Crop,
                    modifier = Modifier
                        .size(64.dp)
                        .clip(CircleShape)
                )

                Spacer(modifier = Modifier.width(12.dp))

                Column(modifier = Modifier.background(Color.Red)) {

                    Text(text = counter.value.toString())
