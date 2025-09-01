package com.example.gdiejava

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.background
import androidx.compose.foundation.clickable
import androidx.compose.foundation.layout.Box
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.shape.CircleShape
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.text.TextStyle
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            Box(
                modifier = Modifier.fillMaxSize(),
                contentAlignment = Alignment.Center
            ) {
                CircleItem()
            }
        }
    }
}

@Composable
private fun CircleItem() {
    val counter = remember { mutableStateOf(0) }
    val color = remember { mutableStateOf(Color.Blue) }

    Box(
        modifier = Modifier
            .size(100.dp)
            .background(color = color.value, shape = CircleShape)
            .clickable {
                counter.value++

                when (counter.value) {
                    10 -> color.value = Color.Red
                    20 -> color.value = Color.Green
                    30 -> color.value = Color.Blue
                }
            },
        contentAlignment = Alignment.Center
    ) {
        Text(
            text = counter.value.toString(),
            style = TextStyle(color = Color.Black, fontSize = 25.sp)
        )
    }
}
