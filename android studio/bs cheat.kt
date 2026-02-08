package com.example.myapplication

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.unit.dp

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            MaterialTheme {
                Surface(
                    modifier = Modifier.fillMaxSize()
                ) {
                    MainScreen()
                }
            }
        }
    }
}

@Composable
fun MainScreen() {
    var check1 by remember { mutableStateOf(false) }
    var check2 by remember { mutableStateOf(false) }
    var check3 by remember { mutableStateOf(false) }

    var red by remember { mutableStateOf(0f) }
    var green by remember { mutableStateOf(0f) }
    var blue by remember { mutableStateOf(0f) }

    val selectedColor = Color(red, green, blue)

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        verticalArrangement = Arrangement.spacedBy(16.dp)
    ) {

        CheckboxRow("Auto Shooting", check1, selectedColor) { check1 = it }
        CheckboxRow("Auto Shooting", check2, selectedColor) { check2 = it }
        CheckboxRow("text3", check3, selectedColor) { check3 = it }

        Divider()

        Text(
            text = "Select color",
            style = MaterialTheme.typography.titleMedium
        )

        ColorSlider("Red", red) { red = it }
        ColorSlider("Green", green) { green = it }
        ColorSlider("Blue", blue) { blue = it }

        Box(
            modifier = Modifier
                .fillMaxWidth()
                .height(50.dp)
                .background(selectedColor)
        )
    }
}

@Composable
fun CheckboxRow(
    text: String,
    checked: Boolean,
    color: Color,
    onCheckedChange: (Boolean) -> Unit
) {
    Row(
        verticalAlignment = Alignment.CenterVertically
    ) {
        Checkbox(
            checked = checked,
            onCheckedChange = onCheckedChange
        )
        Text(
            text = text,
            color = color
        )
    }
}

@Composable
fun ColorSlider(
    label: String,
    value: Float,
    onValueChange: (Float) -> Unit
) {
    Column {
        Text("$label: ${(value * 255).toInt()}")
        Slider(
            value = value,
            onValueChange = onValueChange,
            valueRange = 0f..1f
        )
    }
}
