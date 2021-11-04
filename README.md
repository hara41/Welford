# Welford
Calculate variance by sequential processing.
using "Welford algorithm".

https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance

Welfordアルゴリズムを使って、１サンプルずつデータを渡して標準偏差を計算する。

問題点
・どんどんサンプル数が増えてしまう。
・全データ初期化のリセットしかできない。
・最大サンプル数いくつまでの範囲で計算する改良が必要。
・入力データはlong longとdoubleで作成しているがTemplateを使うべき。


