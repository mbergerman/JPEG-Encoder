const char main_page[] PROGMEM = R"=====(
<HTML>
	<HEAD>
			<TITLE>TP Final ASSD - Grupo 3</TITLE>
	</HEAD>
<BODY>
	<CENTER>
			<B style="font-size:50px">TP Final ASSD - Grupo 3</B><br>
			<p style="font-size:30px">Codificacion de imagenes JPEG<p>
			<p style="font-size:20px">Para codificar la proxima imagen haga</p>
			<a href="encodeJPEG" target="iframeJPEG" style="font-size:20px">CLICK AQUI</a><br><br>
			<iframe name="iframeJPEG" frameBorder="0" width=600 height=600><br>
	</CENTER>	
</BODY>
</HTML>
)=====";

const char sample_jpeg[] PROGMEM = "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";