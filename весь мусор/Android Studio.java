TextView main_text = findViewById(R.id.textView);
        Button btn = findViewById(R.id.button);
        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                showInfo(main_text.getText().toString());
            }
        });

    }
    private void showInfo(String text){
        Toast.makeText(this, text, Toast.LENGTH_SHORT).show();
    }
}


mikhaildotaforedit.siruts@gmail.com
Mikhail2009_._.



ImageButton down = findViewById(R.id.imageButton2);
    MediaPlayer povezlo;
    MediaPlayer don;
    don = MediaPlayer.create(this, R.raw.donbass);
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


private EditText user_name, user_bio;
user_name = findViewById(R.id.ediTextPersonNameid);
        user_bio = findViewById(R.id.editTextTextPersonName2);

public void saveData(View view) {
        String user_name1 = user_name.getText().toString();
        String user_bio1 = user_bio.getText().toString();
        try {
            FileOutputStream fileoutput = openFileOutput("user_data.txt", MODE_PRIVATE);
            fileoutput.write((user_name1 + ". " + user_bio1).getBytes());
            fileoutput.close();

            user_name.setText("");
            user_bio.setText("");
            Toast.makeText(this, "текст сохранен", Toast.LENGTH_LONG).show();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            Toast.makeText(this, "ошибка", Toast.LENGTH_LONG).show();
        } catch (IOException e) {
            e.printStackTrace();
            Toast.makeText(this, "ошибка", Toast.LENGTH_LONG).show();

        }

    }

    public void getData(View view) {
        try {
            FileInputStream fileInput = openFileInput("user_data.txt");
            InputStreamReader reader = new InputStreamReader(fileInput);
            BufferedReader bRead = new BufferedReader(reader);

            StringBuffer stringBuilder = new StringBuffer();

            String lines = "";



            while ((lines = bRead.readLine())  != null){
                stringBuilder.append(lines).append("\n");

            }

            Toast.makeText(this, stringBuilder, Toast.LENGTH_LONG).show();

        } catch (FileNotFoundException e) {
            e.printStackTrace();

        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}

.setOnLongClickListener();



на кнопку к списку 
android:focusable="false"
        android:focusableInTouchMode="false"






public void goBack(View view){
        Intent intent = new Intent (this, MainActivity.class);
        startActivity(intent);



super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list_activiyy);
        Button btnback = findViewById(R.id.btnbackid);

        String[] namesarr = new String[]{"Mikhail", "Makar", "Seva", "Zahar"};
        ListView listView = findViewById(R.id.ListViewId);

        ArrayAdapter<String> adapter = new ArrayAdapter<>(this, R.layout.layoutitem,R.id.btndeleteid ,namesarr);
        listView.setAdapter(adapter);

    }

    public  void GoBack (View view){
        Intent intent = new Intent(this, MainActivity.class);
        startActivity(intent);
    }
}


listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                Toast.makeText(ListActiviyy.this, (String)listView.getItemAtPosition(i), Toast.LENGTH_LONG).show();
            }
        });
 

и к кнопке нужно в параметрах дать

app:layout_constraintEnd_toEndOf = "parent"
        app:layout_constraintTop_toTopOf = "parent"




implements GestureDetector.OnGestureListener ты делаешь жесты



@Override
    public boolean onDown(MotionEvent motionEvent) {
        return false;
    }

    @Override
    public void onShowPress(MotionEvent motionEvent) {

    }

    @Override
    public boolean onSingleTapUp(MotionEvent motionEvent) {
        return false;
    }

    @Override
    public boolean onScroll(MotionEvent motionEvent, MotionEvent motionEvent1, float v, float v1) {
        return false;
    }

    @Override
    public void onLongPress(MotionEvent motionEvent) {

    }

    @Override
    public boolean onFling(MotionEvent motionEvent, MotionEvent motionEvent1, float v, float v1) {
        return false;
    }

Intent intent = new Intent(HelloWorld.this, AboutActivity.class);
startActivity(intent);

fontFamily - шрифт


<?xml version="1.0" encoding="utf-8"?>
<shape xmlns:android = "http://schemas.android.com/apk/res/android"
    android:shape = "rectangle"
    >
    <solid android:color="@color/white" />
    <corners android:radius="10dp"/>
    <stroke android:color="#00c854"
        android:width="7dp"
        />


</shape>








<Button
        android:id = "@+id/button"
        android:layout_width = "319dp"
        android:layout_height = "69dp"
        android:text = "ФІЛІЯЛ БНТУ"

        app:layout_constraintBottom_toBottomOf = "parent"
        app:layout_constraintEnd_toEndOf = "parent"
        app:layout_constraintHorizontal_bias = "0.445"
        app:layout_constraintStart_toStartOf = "parent"
        app:layout_constraintTop_toTopOf = "parent"
        app:layout_constraintVertical_bias = "0.643" />

    <Button
        android:id = "@+id/button2"
        android:layout_width = "319dp"
        android:layout_height = "69dp"


        android:background = "#D3ADAD"
        android:text = "МІНСКАЕ СУВОРАЎСКАЕ ВАЕННАЕ
ВУЧЫЛІШЧА"
        android:textColor = "@color/white"
        android:textColorLink = "#ffffff"
        app:layout_constraintBottom_toBottomOf = "parent"
        app:layout_constraintEnd_toEndOf = "parent"
        app:layout_constraintHorizontal_bias = "0.445"
        app:layout_constraintStart_toStartOf = "parent"
        app:layout_constraintTop_toTopOf = "parent"
        app:layout_constraintVertical_bias = "0.747"
        app:rippleColor = "@android:color/holo_green_dark"
        tools:ignore = "TextContrastCheck,TextContrastCheck" />

    <Button
        android:id = "@+id/button3"
        android:layout_width = "319dp"
        android:layout_height = "69dp"
        android:text = "ДЗЯРЖАЎНАЯ БІБЛІЯТЭКА БССР ІМ. В.
I. ЛЕНІНА"
        app:layout_constraintBottom_toBottomOf = "parent"
        app:layout_constraintEnd_toEndOf = "parent"
        app:layout_constraintHorizontal_bias = "0.445"
        app:layout_constraintStart_toStartOf = "parent"
        app:layout_constraintTop_toTopOf = "parent"
        app:layout_constraintVertical_bias = "0.851" />

    <ImageView
        android:id = "@+id/imageView3"
        android:layout_width = "136dp"
        android:layout_height = "101dp"
        app:layout_constraintBottom_toBottomOf = "parent"
        app:layout_constraintEnd_toEndOf = "parent"
        app:layout_constraintHorizontal_bias = "0.989"
        app:layout_constraintStart_toStartOf = "parent"
        app:layout_constraintTop_toTopOf = "parent"
        app:layout_constraintVertical_bias = "1.0"
        app:srcCompat = "@android:drawable/ic_menu_send" />
