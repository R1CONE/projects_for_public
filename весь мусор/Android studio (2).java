package com.example.aaaaah;

import androidx.appcompat.app.AppCompatActivity;

import android.media.MediaPlayer;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageButton;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ImageButton up = findViewById(R.id.imageButton);
    ImageButton down = findViewById(R.id.imageButton2);
    MediaPlayer povezlo;
    MediaPlayer don;
    don = MediaPlayer.create(this, R.raw.donbas);
    povezlo = MediaPlayer.create(this, R.raw.brue);

        up.setOnClickListener(new View.OnClickListener() {
        @Override
        public void onClick(View view) {
            soundPlayButton(don);
        }
    });

}

    private void soundPlayButton(MediaPlayer sound) {
        if(sound.isPlaying()){
            sound.stop();

        }
        sound.start();
    }
}
