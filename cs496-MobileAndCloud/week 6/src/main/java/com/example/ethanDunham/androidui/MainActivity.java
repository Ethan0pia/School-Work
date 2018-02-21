package com.example.ethanDunham.androidui;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView listViewItemVer = findViewById(R.id.button1);
        listViewItemVer.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, ListViewVerActivity.class);
                startActivity(intent);
            }
        });

        TextView listViewItemHor = findViewById(R.id.button2);
        listViewItemHor.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, ListViewHorActivity.class);
                startActivity(intent);
            }
        });

        TextView relativeViewItem = findViewById(R.id.button3);
        relativeViewItem.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, RelativeViewActivity.class);
                startActivity(intent);
            }
        });

        TextView gridViewItem = findViewById(R.id.button4);
        gridViewItem.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                Intent intent = new Intent(MainActivity.this, GridViewActivity.class);
                startActivity(intent);
            }
        });
    }
}
