const char * bestHand(
	const int * const ranks,
	const int ranksLen,
	const char * const suits,
	const int suitsLen
){
	assert(5 == ranksLen && 5 == suitsLen);

	bool suitSame = true;
	for (int i = 1; i < 5; i += 1){
		if (suits[i] != suits[0]){
			suitSame = false;
			break;
		}
	}
	if (suitSame){
		return "Flush";
	}

	int freqs[13];
	memset( &freqs, 0, sizeof (freqs) );
	for (int i = 0; i < 5; i += 1){
		assert(ranks[i] >= 1 && ranks[i] <= 13);
		freqs[ ranks[i] - 1 ] += 1;
	}
	int max = freqs[0];
	for (int i = 0; i < 13; i += 1){
		if (freqs[i] > max){
			max = freqs[i];
		}
	}
	if (max >= 3){
		return "Three of a Kind";
	}else if (2 == max){
		return "Pair";
	}

	return "High Card";
}