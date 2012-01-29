/**
 * Gets CPU thicks measure using XPCOM component
 */
var sampler = {
	init: function() {
		try {
			greenfox;
			return true;
		} catch( e ) {
			return false;
		}		
	},
	destroy: function() {},
	startMeasure: function() {
		greenfox.start();
	},
	endMeasure: function() {
		var thicks = greenfox.stop();
		return thicks;
	},
}

/**
 * Gets CPU thicks measure. This objet is just a mock.
 */
var mockSampler = {
	init: function() {
		return true;
	},
	destroy: function() {},
	startMeasure: function() {
	},
	endMeasure: function() {
		return Math.floor(Math.random() * 100000000);
	},
}


