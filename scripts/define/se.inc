## ドアノック #################################################################
MACRO	se_door_nock
se	0,	"sound\se\ノック１.wav",	play_wait
ENDMACRO
## ドア閉じる #################################################################
MACRO	se_door_close
se	0,	"sound\se\ドア開閉音３.wav",	play_wait
ENDMACRO
## ドア閉じる #################################################################
MACRO	se_door_open
se	0,	"sound\se\ドア開閉音２.wav",	play_once
ENDMACRO

#SE01　ズボンのベルトを外す（カチャカチャ）
macro	SE01
	window_close
	se	0,	"sound\se\SE01_ベルトを外す.wav",		play_wait
endm

#SE02　布団に倒れる・布団を跳ね上げる（バフッ！！）
macro	SE02
	window_close
	se	0,	"sound\se\SE02_バフッ.wav",		play_once
endm

#SE03　自宅の電話音
macro	SE03
	se	0,	"sound\se\SE03_自宅の電話音.wav",	play_once
endm

#SE04　バスが走り去る音
macro	SE04
	se	0,	"sound\se\SE04_バスが走り去る音.wav",	play_once
endm

#SE05　物にぶつかる音（ガンッ！）※ギャグ調なので、リアルっぽくない擬音系
macro	SE05
	window_close
	screen_vibration	500,16,16,16
	se	0,	"sound\se\SE05_ずっこけドカン.WAV",	play_wait
endm

#部屋のドア開く音（ガチャ）
macro	SE06
	window_close
	se	0,	"sound\se\ドア4～あける.WAV",		play_wait
endm

#部屋のドア閉まる音（パタン）
macro	SE07
	se	0,	"sound\se\ドア4～しめる.WAV",		play_wait
endm

#SE08　部屋のドアが乱暴に開く音・閉まる音（バンッ！！）
macro	SE08
	window_close
	se	0,	"sound\se\ドア4～あける.WAV",		play_once
	wait	500
	screen_vibration	500,16,16,16
	se	0,	"sound\se\ドア4～しめる.WAV",		play_wait
endm

#部屋のドアの鍵を掛ける音（カチャ）
macro	SE09
	se	0,	"sound\se\SE09_カギ ３.WAV",	play_wait
endm

#鍵の掛かった部屋のドアノブを回す音（ガチャガチャ）
macro	SE10
	se	0,	"sound\se\開かないドア.wav",		play_wait
endm

#SE11　部屋のドアをノック（コンコン）
macro	SE11
	window_close
	se	0,	"sound\se\SE11_ノック１.wav",		play_wait
endm

#SE12　部屋のドアを乱暴にノック（ダンダンダン！）
MACRO	SE12
	se	0,	"sound\se\SE12_木のドア_ノック_乱暴.wav",play_once
ENDMACRO


#お腹の音・弱（キュルル……）
MACRO	SE13
	window_close
	se	0,	"sound\se\SE13_お腹が鳴る.WAV",		play_once
	wait	2000
ENDMACRO

#小物が弧を描き飛ぶこと
MACRO	SE14
	se	0,	"sound\se\SE14_小物が弧を描き飛ぶこと.wav",play_once
ENDMACRO

#SE15　目覚ましの音（ジリリリリッ！）
MACRO	SE15
	se	0,	"sound\se\SE15_目覚まし時計～ベル１.WAV",play_loop
ENDMACRO

#SE16　廊下を歩く音
MACRO	SE16
	se	0,	"sound\se\SE16_足音_アスファルト女性.wav",play_loop
ENDMACRO

#SE17　廊下を歩いてくる音　※徐々に大きく
MACRO	SE17
	se	0,	"sound\se\SE17_足音７.WAV",play_once
ENDMACRO

#廊下を歩き去る音
MACRO	SE18
	window_close
	se	0,	"sound\se\足音_絨毯女性.wav",		play_wait
ENDMACRO

#SE19　廊下を走る音
MACRO	SE19
	se	0,	"sound\se\wood 11.wav",		play_loop
ENDMACRO

#SE20　廊下を走ってくる音　※徐々に大きく
MACRO	SE20
	window_close
	se	0,	"sound\se\SE20_足音2～走ってくる.wav",play_wait
ENDMACRO

#SE21　廊下を走り去る音　※徐々に小さく
MACRO	SE21
	se	0,	"sound\se\SE21_足音2～走り去る.wav",play_once
ENDMACRO

#SE22　水を浴びる音（バシャアァァン！）
MACRO	SE22
	se	0,	"sound\se\身体に水をかける.wav",play_once
ENDMACRO

#青ノリを振り掛ける音（ザッザッザッ）
MACRO	SE23
	se	0,	"sound\se\SE23_青ノリを振りかける.WAV",	play_wait
ENDMACRO

#SE24　物音（ガタンッ）
MACRO	SE24
	se	0,	"sound\se\SE24_ガラス戸を乱暴に閉める～ガタン.wav",	play_once
ENDMACRO

#SE25　部屋のドアがゆっくり軋みながら開く音（ギィィィィ……）
MACRO	SE25
	se	0,	"sound\se\SE25_部屋のドアがゆっくり軋みながら開く音.WAV",	play_once
ENDMACRO

#SE26　柔らかい物との衝突音（バフンッ！！）※クッションや枕などをぶつけられた音
MACRO	SE26
	screen_vibration	1000,16,16,16
	se	0,	"sound\se\SE02_バフッ.wav",	play_once
ENDMACRO

#SE27　倒れる音（ドサッ）
MACRO	SE27
	screen_vibration	500,16,16,16
	se	0,	"sound\se\落ちた衝撃音～ゴトンッ.WAV",	play_once
ENDMACRO

#SE28　机や引き出しを漁る音（ガタッ、ゴソゴソゴソ……）
MACRO	SE28
	se	0,	"sound\se\SE28_タンス・あける.WAV",	play_once
ENDMACRO

#SE29　バイブが動く音（ウィィンウィィン）
MACRO	SE29
	se	0,	"sound\se\vibD-loop.wav",	play_loop
ENDMACRO

#SE30　玄関のドアが開く音
MACRO	SE30
	se	0,	"sound\se\SE30_木製ドア～あける１.WAV",	play_once
ENDMACRO

#SE31　玄関のドアが閉まる音
MACRO	SE31
	se	0,	"sound\se\SE31_木製ドア～しめる１.WAV",	play_once
ENDMACRO

#SE32　外で走る音
MACRO	SE32
	se	0,	"sound\se\wood 11.wav",		play_loop
ENDMACRO

#SE33　外で走ってくる音
MACRO	SE33
	window_close
	se	0,	"sound\se\SE20_足音2～走ってくる.wav",	play_wait
ENDMACRO

#SE34　外で走り去る音
MACRO	SE34
	se	0,	"sound\se\SE21_足音2～走り去る.wav",	play_once
ENDMACRO

#ティーカップを置く音（カチャ）
MACRO	SE35
	window_close
	se	0,	"sound\se\ティーカップを皿に戻す音.wav",play_wait
ENDMACRO

#SE36　勢いよく抱きつく音（バフッ！）
MACRO	SE36
	window_close
	screen_vibration	500,16,16,16
	se	0,	"sound\se\SE02_バフッ.wav",play_wait
ENDMACRO

#SE37　金属衝突音（カキィンッ！）※剣で打ち合った感じ。擬音的な役割で汎用的に使
MACRO	SE37
	window_close
	screen_vibration	500,16,16,16
	screen_flash	500
	se	0,	"sound\se\SE37_金属衝突音.WAV",play_wait
ENDMACRO

#殴る音（バキッ！）
MACRO	SE38
	screen_flash		500
	screen_vibration	500,16,16,16
	se		0,"sound\se\なぐる2～強く.WAV",play_wait
ENDMACRO

#SE39　積んでいた物が崩れる音（ドシャドシャッ、ガララッ）
MACRO	SE39
	se	0,	"sound\se\SE39_積んでいた物が崩れる音.wav",	play_once
ENDMACRO

#SE40　リコーダーの練習音
MACRO	SE40
#	se	0,	"sound\se\SE21_足音2～走り去る.wav",	play_once
ENDMACRO

#SE41　暴れる音（ドタンッバタンッ！）
MACRO	SE41
	screen_vibration	500,16,16,16
	se		0,"sound\se\なぐる2～強く.WAV",play_once
	wait	100
	screen_vibration	500,16,16,16
	se		0,"sound\se\なぐる2～強く.WAV",play_once
	wait	500
	screen_vibration	500,16,16,16
	se		0,"sound\se\なぐる2～強く.WAV",play_once
	wait	200
	screen_vibration	500,16,16,16
	se		0,"sound\se\なぐる2～強く.WAV",play_once
	wait	300
	screen_vibration	500,16,16,16
	se		0,"sound\se\なぐる2～強く.WAV",play_once
	wait	100
	screen_vibration	500,16,16,16
	se		0,"sound\se\なぐる2～強く.WAV",play_once
	wait	100
ENDMACRO

#SE42　孤児院の呼び鈴
MACRO	SE42
	window_close
	se	0,	"sound\se\SE42_孤児院の呼び鈴.wav",	play_wait
ENDM

#SE43　紙を破る音（ビィィッ！　ビリリッ！）※包装紙などを破いたり
MACRO	SE43
	se	0,	"sound\se\SE43_紙～破る.WAV",	play_once
ENDM

#SE44　電子音（ピッ）※テレビのスイッチなど
MACRO	SE44
	se	0,	"sound\se\SE44_電子音.wav",	play_once
ENDM

#SE45　雪の上に倒れる音（ズシャッ）
MACRO	SE45
	se	0,	"sound\se\ずっこけドイン.WAV",	play_once
ENDM

#SE46　雪の上を歩く音
MACRO	SE46
	se	0,	"sound\se\SE46_雪の上を歩く音.wav",	play_once
ENDM

#SE47　テーブルを叩く音（バンッ！）
MACRO	SE47
	screen_vibration	500,16,16,16
	se	0,	"sound\se\SE47_テーブルを叩く音.wav",	play_once
ENDM

#SE48　柔肉音１（ムニュッ）
MACRO	SE48
	window_close
#	screen_vibration	500,16,16,16
	se		0,"sound\se\プイッ.WAV",play_wait
ENDMACRO

#SE49　草を掻き分ける音（ガサガサ）
MACRO	SE49
	se	0,	"sound\se\SE49_草を掻き分ける音.wav",	play_once
ENDM

#SE50　風を切る音（ヒュンッ）
MACRO	SE50
	window_close
	screen_vibration	500,16,16,16
	se	0,	"sound\se\SE50_空を切る.WAV",	play_wait
ENDM

#SE51　肉を焼く油音（ジュゥゥッ）※焼肉時に使います
MACRO	SE51
	se	0,	"sound\se\SE51_肉を焼く油音.WAV",	play_once
ENDM

#SE52　水しぶき（バシャバシャ）
MACRO	SE52
	se	0,	"sound\se\SE52_水しぶき.wav",	play_once
ENDM

#SE53　傷つく言葉（グサッ！）
MACRO	SE53
	screen_flash		500
	screen_vibration	500,16,16,16
	se	0,	"sound\se\SE53_ズビシ.WAV",			play_once
ENDMACRO

#SE54　火球音　※ゲームブックで使用
MACRO	SE54
	se	0,	"sound\se\SE54_火球音.WAV",	play_once
ENDM

#SE55　凍てつき音　※擬音系。ゲームブックで使用
MACRO	SE55
	se	0,	"sound\se\SE55_凍てつき音.WAV",	play_once
ENDM

#SE56　魔法衝撃音　※擬音系。ゲームブックで使用
MACRO	SE56
	se	0,	"sound\se\SE56_魔法衝撃音.WAV",	play_once
ENDM

#SE57　爆発音　※ゲームブックで使用
MACRO	SE57
	se	0,	"sound\se\SE57_爆発音.WAV",	play_once
ENDM

#SE58　魔法集束音　※擬音系。ゲームブックで使用
MACRO	SE58
	se	0,	"sound\se\SE58_魔法集束音.WAV",	play_once
ENDM

#SE59　衝撃に吹き飛ぶ音　※ゲームブックで使用
MACRO	SE59
	se	0,	"sound\se\SE59_衝撃に吹き飛ぶ音.WAV",	play_once
ENDM

#SE60　斬激　※ゲームブックで使用
MACRO	SE60
	screen_flash		500
	screen_vibration	500,16,16,16
	se	0,	"sound\se\SE60_斬激.WAV",	play_once
ENDM

#SE61　斬激＋消滅音　※ゲームブックで使用
MACRO	SE61
	se	0,	"sound\se\SE61_斬激消滅音.wav",	play_once
ENDMACRO


#SE62　中ラッシュ１　※ゲームブックで使用（既存の攻撃音や衝撃音をつなげて表現）
MACRO	SE62
	se	0,	"sound\se\SE62_中ラッシュ１.wav",	play_once
ENDMACRO

#SE63　中ラッシュ２　※ゲームブックで使用（既存の攻撃音や衝撃音をつなげて表現）
MACRO	SE63
	se	0,	"sound\se\SE63_中ラッシュ２.wav",	play_once
ENDMACRO


#SE64　長ラッシュ　※ゲームブックで使用（既存の攻撃音や衝撃音をつなげて表現）
MACRO	SE64
	se	0,	"sound\se\SE64_長ラッシュ.wav",	play_once
ENDMACRO

#寝ている人の上に飛び乗る音
MACRO	SE65
screen_vibration	1000,8,1,32
layer_scale		0,1000,5,5,0,0,passtype_tcb
se		0,"sound\se\ずっこけドイン.WAV",play_once
ENDMACRO

#効果音１（ビシッ！）※場面を強調したりする効果音
MACRO	SE66
	layer_scale	0,500,5,5,0,0,passtype_tcb
#	screen_vibration	500,8,16,16
	se	0,	"sound\se\SE66　効果音１_ビシッ！.WAV",	play_once
ENDMACRO

#食事を噴き出す音（ブゥゥッ！！）
MACRO	SE67
	se	0,	"sound\se\SE67_食事を噴き出す音.wav",play_once
ENDMACRO

# 電気のスイッチ
MACRO	SE68
	se	0,	"sound\se\SE68_電灯スイッチ３.wav",	play_wait
ENDMACRO

#SE69　物をこかす音（ガシャン）
MACRO	SE69
	se	0,	"sound\se\SE69_物をこかす音.wav",	play_once
ENDMACRO

#SE70　衣擦れ音（シュルシュル）
MACRO	SE70
	window_close
	se	0,	"sound\se\SE70_衣擦れ音.wav",	play_wait
ENDMACRO

#SE71　目覚ましが止まる音（リンッ）
MACRO	SE71
	se	0,	"sound\se\SE71_目覚ましが止まる音.wav",	play_once
ENDMACRO

#---------------------------------------------------------------------------

#SE72　軽く叩く音（ポカッ）
macro	SE72
	window_close
	screen_flash		500
	screen_vibration	500,8,8,8
	se 0,"sound\se\SE72_軽く叩く音.wav",play_once
endm

#SE73　風が吹きぬける音（ヒュゥゥウ）※擬音系。場が冷めた時とかに使う場面効果。
macro	SE73
	window_close
	se 0,"sound\se\SE73_風が吹きぬける音.wav",play_wait
endm

#SE74　目の輝き（キラーン）
macro	SE74
	se 0,"sound\se\SE74_目の輝き.WAV",play_once
endm

#SE75　ショック音（ガーーン！）
macro	SE75
	se 0,"sound\se\SE75_がーん.WAV",play_once
endm

#SE76　雪の山が被さる音（ドサァアッ！）
macro	SE76
	se 0,"sound\se\SE76_雪の山が被さる音.wav",play_once
endm

#SE77　雪の上を走り去る音
macro	SE77
	se 0,"sound\se\SE77_雪の上を走り去る音.wav",play_once
endm

#SE78　ビーブ音・間違い（ブブーッ！）
macro	SE78
	se 0,"sound\se\SE78_ビーブ音・間違い.WAV",play_once
endm

#SE79　ページを捲る音（ペラッ）※２ギガやレクイエムで使っていた音でもＯＫです
macro	SE79
	se 0,"sound\se\SE79_ページを捲る音.wav",play_wait
endm

#SE80　人を刺す音（グシュッ！）　※シリアス系です。バッドエンドとか、刺されるときに使用。
macro	SE80
	se 0,"sound\se\SE80_人を刺す音.WAV",play_once
endm

#SE81　外を歩く音（スタスタスタスタ）
#macro	SE81
#	se 0,"sound\se\",play_once
#endm

#SE82　外を歩き去る音　※徐々に小さく
macro	SE82
	@se21
#	se 0,"sound\se\",play_once
endm

#SE83　外を歩いてくる音　※徐々に大きく
#（欠番）

#SE84　ガヤ１・人のざわめき（ザワザワザワ）※適切な音が無ければ、こちらでガヤ用の台詞を用意して収録後に編集します。
macro	SE84
	se 0,"sound\se\SE84_ガヤ１・人のざわめき.WAV.wav",play_once
endm

#SE85　花火の効果音・打ち上げ
macro	SE85
	se 0,"sound\se\SE85_花火の効果音・打ち上げ.wav",play_once
endm

#SE86　花火の効果音・散花
macro	SE86
	se 0,"sound\se\SE86_花火の効果音・散花.wav",play_once
endm

#SE87　効果音２（ゴーン）※暗く落ち込んでいるシーンに使用
macro	SE87
	se 0,"sound\se\SE87_効果音２（ゴーン）.wav",play_once
endm

#SE88　ボートを漕ぐ水音（チャプっ、チャプンっ）
macro	SE88
	se 0,"sound\se\SE88_ボートを漕ぐ水音.wav",play_once
endm

#SE89　壁を殴る音（既存のSEで合うものがあれば使いまわし。無ければ新規でお願いします）
macro	SE89
	se 0,"sound\se\SE89_壁を殴る音.wav",play_once
endm

#SE90　雨音（ザアァァ！）
macro	SE90
	se 0,"sound\se\SE90_雨音.wav",play_once
endm

#SE91　雨の中を走る音（パシャッパシャッパシャッパシャッ！）
macro	SE91
	se 0,"sound\se\SE91_雨の中を走る音.wav",play_once
endm

#SE92　物を蹴る音（ガシャッ！）（既存のSEで合うものがあれば使いまわし。無ければ新規でお願いします）
macro	SE92
	se 0,"sound\se\SE24_ガラス戸を乱暴に閉める～ガタン.wav",play_once
endm

#SE93　銃の乱射音（ダダダダダダッ！）
macro	SE93
	se 0,"sound\se\SE93_銃の乱射音.wav",play_once
endm

#SE94　銃声
macro	SE94
	se 0,"sound\se\SE94_銃声.wav",play_once
endm

#SE95　人を殴る音　※リアル
macro	SE95
	se 0,"sound\se\SE89_壁を殴る音.wav",play_once
endm

#SE96　リノリウムの床（廊下）を走る音
macro	SE96
	se 0,"sound\se\SE96_廊下を走る音.WAV",play_once
endm

#SE97　金属を打ち付ける鈍い音
#macro	SE97
#	se 0,"sound\se\",play_once
#endm

#SE98　レストランのドアベル（カランカラン）
macro	SE98
	se 0,"sound\se\SE98_レストランのドアベル.wav",play_once
endm

#SE99　お皿などを大量に割った音（ガシャガシャッ、ガシャーン！）
macro	SE99
	se 0,"sound\se\SE99_お皿などを大量に割った音.wav",play_once
endm

#SE100　服を破る（ビリビリッ！）
macro	SE100
	se 0,"sound\se\SE100_服を破る.wav",play_once
endm

#SE101　車の音（小さめ）
macro	SE101
	se 0,"sound\se\SE101_車の音小.wav",play_once
endm

#SE102　車の音（大きめ）
macro	SE102
	se 0,"sound\se\SE102_車の音大.wav",play_once
endm

#SE103　車が衝突・事故
macro	SE103
	se 0,"sound\se\SE103_車が衝突.wav",play_once
endm

#SE104　火が燃える音
macro	SE104
	se 0,"sound\se\SE104_火が燃える音.wav",play_once
endm

#SE105　拍手・一人（盛大なものではない。雫が感心するシーンで打つもの）
macro	SE105
	se 0,"sound\se\SE105_拍手・一人.wav",play_once
endm

#SE106　銃の装備（ガシャッ・カシャンッ）※銃器を装備したり動かすときに聞く音です。
macro	SE106
	se 0,"sound\se\SE106_銃の装備..wav",play_once
endm

#SE107　重い機械音・仕掛けの駆動音（グオングオン）※それっぽい擬音
macro	SE107
	se 0,"sound\se\SE107_重い機械音.WAV",play_once
endm

#SE108　女性のビンタ（パシンッ！）
macro	SE108
	se 0,"sound\se\SE108_女性のビンタ.WAV",play_once
endm

#SE109　ヘリのローター回転音（ババババババ！）
macro	SE109
	se 0,"sound\se\SE109_ヘリのローター回転音.wav",play_once
endm

#SE110　カメラのタイマーの音（ジイィィ……）
macro	SE110
	se 0,"sound\se\SE110_カメラのタイマーの音.WAV",play_once
endm

#SE111　カメラのシャッターの音（パシャッ）
macro	SE111
	se 0,"sound\se\SE111_カメラのシャッターの音.wav",play_once
endm

#SE112　浴室のドアスライド（カラカラカラ）
macro	SE112
	se 0,"sound\se\SE112_浴室のドアスライド.wav",play_once
endm

#SE113　アイテムゲット（ピロリロリン！）
macro	SE113
	se 0,"sound\se\SE113_アイテムゲット.WAV",play_once
endm

#SE114　サイコロをまわす音　※擬音
macro	SE114
	window_close
	se 0,"sound\se\SE114_サイコロをまわす音.wav",play_wait
endm

#SE115　草原を歩く音
macro	SE115
	se 0,"sound\se\SE115_草原を歩く音.wav",play_once
endm

#SE116　エンカウントジングル
macro	SE116
	se 0,"sound\se\SE116_エンカウントジングル.WAV",play_once
endm

#SE117　戦闘勝利ジングル
macro	SE117
	se 0,"sound\se\SE117_戦闘勝利ジングル.WAV",play_once
endm

#SE118　戦闘敗北ジングル
macro	SE118
	se 0,"sound\se\SE118_戦闘敗北ジングル.WAV",play_once
endm

#SE119　ターン切り替え音
macro	SE119
	se 0,"sound\se\SE119_ターン切り替え音2.WAV",play_once
endm

#SE120　酒場のドア（ギイィ）
macro	SE120
	se 0,"sound\se\SE120_酒場のドア.WAV",play_once
endm

#SE121　酒場の喧騒（ガヤガヤと酒場的なループ効果音）
macro	SE121
	se 0,"sound\se\SE121_酒場の喧騒.WAV",play_once
endm

#SE122　何かが弾け飛び出る音？（バシュッ！シュルルル！）※ＴＲＰＧ世界で、種から急に植物が増殖する時に使います。
macro	SE122
	se 0,"sound\se\SE122_何かが弾け飛び出る音.WAV",play_once
endm

#SE123　蔦の這い回る音（触手として使うので、少し不気味な感じで）
macro	SE123
	window_close
	se 0,"sound\se\SE123_蔦の這い回る音.WAV",play_once
	wait	1000
endm

#SE124　蔦の這い回る音＋粘液（触手として使うので、少し不気味な感じで）
macro	SE124
	window_close
	se 0,"sound\se\SE124_蔦の這い回る音・粘液.wav",play_once
	wait	1000
endm

#SE125　ボスモンスターの咆哮（グオオオオオオッ！！！）
macro	SE125
	se 0,"sound\se\SE125_ボスモンスターの咆哮.WAV",play_once
endm

#SE126　回復音（回復っぽい音なら、何でもOKです）
macro	SE126
	se 0,"sound\se\SE126_回復音.WAV",play_once
endm

#SE127　敵消滅音
macro	SE127
	se 0,"sound\se\SE127_敵消滅音.wav",play_once
endm

#SE128　洞窟の足音（響く感じ）
macro	SE128
	se 0,"sound\se\SE128_洞窟の足音.wav",play_once
endm

#SE129　宝箱を開ける音
macro	SE129
	se 0,"sound\se\SE129_宝箱開ける.WAV",play_once
endm

#SE130　怒り・空気が固まる擬音（ピシッ！）or（ピキィン！）
macro	SE130
	se 0,"sound\se\SE130_怒り・空気が固まる擬音.wav",play_once
endm





#SE213_乾杯.WAV
macro	SE213
	se 0,"sound\se\SE213_乾杯.WAV",play_once
endm

#SE214_液体を注ぐ音.WAV
macro	SE214
	se 0,"sound\se\SE214_液体を注ぐ音.WAV",play_once
endm

#SE215 好感度アップ
macro	SE215
	se 0,"sound\se\SE215_好感度アップ.WAV",play_once
endm

#SE216_ドラムロール.wav
macro	SE216
	se 0,"sound\se\SE216_ドラムロール.wav",play_once
	wait	1000
endm

#SE217_ファンファーレ.wav
macro	SE217
	se 0,"sound\se\SE217_ファンファーレ.wav",play_once
endm

#SE218_お金が減る.wav
macro	SE218
	se 0,"sound\se\SE218_お金が減る.wav",play_once
endm

#SE219_がっかり.wav
macro	SE219
	se 0,"sound\se\SE219_がっかり.wav",play_once
endm

#SE220_柵が揺れる音.wav
macro	SE220
	se 0,"sound\se\SE220_柵が揺れる音.wav",play_once
endm

#SE223_車いすの軋み.wav
macro	SE223
	se 0,"sound\se\SE223_車いすの軋み.wav",play_once
endm

#-----------------------------------------------------------------------------

#SEH01_ジッパー下げる
macro	SEH01
	se 0,"sound\se\SEH01_ジッパー下げる.wav",play_once
endm

#SEH02_スパンキング１
macro	SEH02
	screen_vibration	500,16,16,16
	screen_flash		500
	se 0,"sound\se\SEH02_スパンキング１.wav",play_once
endm

#SEH03_スパンキング２
macro	SEH03
	se 0,"sound\se\SEH03_スパンキング２.wav",play_once
endm

#SEH04_バイブ（低い）
macro	SEH04
	se 1,"sound\se\SEH04_バイブ（低い）.wav",play_loop
endm

#SEH05_バイブ（高い）
macro	SEH05
	se 1,"sound\se\SEH05_バイブ（高い）.wav",play_loop
endm

#SEH06_引き抜く１
macro	SEH06
	se 0,"sound\se\SEH06_引き抜く１.wav",play_once
endm

#SEH07_鎖
macro	SEH07
	se 0,"sound\se\SEH07_鎖.wav",play_once
endm

#SEH08_射精音１
macro	SEH08
	se 0,"sound\se\SEH08_射精音１.wav",play_once
endm

#SEH09_射精音２
macro	SEH09
	se 0,"sound\se\SEH09_射精音２.wav",play_once
endm

#SEH10_手コキ
macro	SEH10
	se 0,"sound\se\SEH10_手コキ.wav",play_once
endm

#SEH11 小便
macro	SEH11
	se 0,"sound\se\SEH11_小便.wav",play_once
endm

#SEH12_針を刺す.wav
macro	SEH12
	se 0,"sound\se\SEH12_針を刺す.wav",play_once
endm

#SEH13_鞭か何かで叩かれる１.wav
macro	SEH13
	screen_vibration	1000,32,16,16
	se 0,"sound\se\SEH13_鞭か何かで叩かれる１.wav",play_once
endm

#SEH15_鞭か何かで叩かれる２.wav
macro	SEH15
	screen_vibration	1000,32,16,16
	se 0,"sound\se\SEH15_鞭か何かで叩かれる２.wav",play_once
endm

#SEH16_油性マジックで体にいたずら書きする音.wav
macro	SEH16
	se 0,"sound\se\SEH16_油性マジックで体にいたずら書きする音.wav",play_once
endm

#SEH17_浣腸液が流れ込んでいく音.wav
macro	SEH17
	se 0,"sound\se\SEH17_浣腸液が流れ込んでいく音.wav",play_once
endm

#SEH18_排便.wav
macro	SEH18
	se 0,"sound\se\SEH18_排便.wav",play_once
endm

#SEH19_おなら.wav
macro	SEH19
	se 0,"sound\se\SEH19_おなら.wav",play_once
endm

#SEH20_一本鞭.wav
macro	SEH20
	se 0,"sound\se\SEH20_一本鞭.wav",play_once
endm

#SEH13 小便
macro	SEH21
	se 0,"sound\se\SEH12_小便.wav",play_once
endm

#SEH22_挿入音.wav
macro	SEH22
	se 0,"sound\se\SEH22_挿入音.wav",play_once
endm

#SEH23_ピストン遅い.wav
macro	SEH23
	se 1,"sound\se\SEH23_ピストン遅い.wav",play_loop
endm

#SEH24_ピストン普通.wav
macro	SEH24
	se 1,"sound\se\SEH24_ピストン普通.wav",play_loop
endm

#SEH25_ピストン速い.wav
macro	SEH25
	se 1,"sound\se\SEH25_ピストン速い.wav",play_loop
endm

#SEH26_舐める音.wav
macro	SEH26
	se 1,"sound\se\SEH26_舐める音.wav",play_loop
endm

#SEH27_手マン遅い.wav
macro	SEH27
	se 1,"sound\se\SEH27_手マン遅い.wav",play_loop
endm

#SEH28_手マン普通.wav
macro	SEH28
	se 1,"sound\se\SEH28_手マン普通.wav",play_loop
endm

#SEH29_手マン速い.wav
macro	SEH29
	se 1,"sound\se\SEH29_手マン速い.wav",play_loop
endm

#SEH30_ものすごい排便.wav
macro	SEH30
	se 0,"sound\se\SEH30_ものすごい排便.wav",play_once
endm

#SEH31_ローション.wav
macro	SEH31
	se 0,"sound\se\SEH31_ローション.wav",play_once
endm

#SEH32_首輪や手錠を閉める.wav
macro	SEH32
	se 0,"sound\se\SEH32_首輪や手錠を閉める.wav",play_once
endm

#SEH33_縄で縛られる.wav
macro	SEH33
	se 0,"sound\se\SEH33_縄で縛られる.wav",play_once
endm

#SEH34_ズボンを脱ぐ.wav
macro	SEH34
	se 0,"sound\se\SEH34_ズボンを脱ぐ.wav",play_once
endm

#SEH35_精液を注ぐ.wav
macro	SEH35
	se 0,"sound\se\SEH35_精液を注ぐ.wav",play_once
endm

#SEH36_ローター.wav
macro	SEH36
	se 1,"sound\se\SEH36_ローター小.wav",play_loop
endm

#SEH37_ローター大.wav
macro	SEH37
	se 1,"sound\se\SEH37_ローター大.wav",play_loop
endm

#SEH38_電マ.wav
macro	SEH38
	se 1,"sound\se\SEH38_電マ.wav",play_loop
endm


macro	SE_HIRATEUCHI
	se	0,	"sound\se\平手打ち.wav",play_once
	screen_flash		500
	screen_vibration	500,16,16,16
endm

#携帯バイブ
macro	SE_KEITAI1
	se	0,	"sound\se\携帯バイブ音.wav",play_loop
endm

#携帯着信
macro	SE_KEITAI2
	se	0,	"sound\se\電話プッシュ音_ピ.wav",play_wait
endm

#ショックな音
macro	SE_SHOCK
	se	0,	"sound\se\がーん.wav",play_once
endm

#ショックな音
macro	SE_ITEMGET
	@se113
endm



