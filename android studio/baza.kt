package com.example.gdiejava

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.*
import androidx.compose.runtime.Composable
import androidx.compose.ui.Alignment   // ✅ правильный Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.sp

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            NewText()
        }
    }
}

@Preview(showBackground = true)
@Composable
fun NewText() {
    Box(
        modifier = Modifier.fillMaxSize(),
        contentAlignment = Alignment.Center
    ) {
        Text(
            text = "Hello! $",
            fontSize = 40.sp
        )
    }
    
}




package com.example.gdiejava

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.Text
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            Row(
                modifier = Modifier
                    .background(Color.Gray)
                    .fillMaxSize(), // растягиваем весь Row
                verticalAlignment = Alignment.CenterVertically
            ) {
                Column(
                    modifier = Modifier
                        .weight(1f) // половина ширины
                        .fillMaxHeight()
                        .background(Color.Red),
                    verticalArrangement = Arrangement.SpaceAround,
                    horizontalAlignment = Alignment.CenterHorizontally
                ) {
                    Text(text = "Hello")
                    Text(text = "Girona")
                    Text(text = "Madrid")
                }

                Column(
                    modifier = Modifier
                        .weight(1f) // вторая половина ширины
                        .fillMaxHeight(0.85f)
                        .background(Color.Green),
                    verticalArrangement = Arrangement.SpaceAround,
                    horizontalAlignment = Alignment.End
                ) {
                    Text(text = "Hello")
                    Text(text = "Girona")
                    Text(text = "Madrid")
                }
            }
        }
    }
}
