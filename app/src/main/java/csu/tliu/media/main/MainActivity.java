package csu.tliu.media.main;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import csu.tliu.ndk.media.FfmpegAudioPlayer;
import csu.tliu.ndk.media.OnPrepaerListener;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


    }

    public void clickButton(View view) {
        new FfmpegAudioPlayer().prepare(new OnPrepaerListener() {
            @Override
            public void onSucess() {
                Log.d("lalalalal", "sucess");
            }

            @Override
            public void onFailed(String message) {

            }
        });
    }

    public void clcikOther(View view) {
        Toast.makeText(this, "you click me!", Toast.LENGTH_SHORT).show();
    }
}
