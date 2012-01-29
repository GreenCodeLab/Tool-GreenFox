/**
 * Send samples to the collect server.
 */
var greenfoxCollect = {

	prefs: null,
	
	init: function() {
		// Get out prefs:
		this.prefs = Components.classes["@mozilla.org/preferences-service;1"]
		     .getService(Components.interfaces.nsIPrefService)
		     .getBranch("extensions.greenfox.");

		this.readPrefs();
	},
	readPrefs: function() {
		this.endpoint = this.prefs.getCharPref('endpoint')
		this.challengerID = this.prefs.getCharPref('challengerID')
	},
	destroy: function() {
	},
	willSendSamples: function() {
		return true
	},

	/**
	 * Send sample.
	 * @param sample sample (number)
	 */
	postSample: function(sample) {
		
		var endpoint = this.endpoint;
		var challengerID = encodeURIComponent(this.challengerID);
		var postDataString = 'challengerID='+challengerID+'&CPUCycles='+sample+'&source=GREEN_FOX';
	
		// Post data:
		var xhr = new XMLHttpRequest();
		try {
			xhr.open('POST', endpoint, false );
			xhr.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
			xhr.setRequestHeader("Content-length", postDataString.length);
			xhr.setRequestHeader("Connection", "close");
			xhr.send(postDataString);
		} catch( e ) {
			window.alert('GreenFox failed to send sample, please check the network');
			return false;
		}
		
		if( xhr.status == 200 ) {
			// Tutti va bene...
			return true;
		} else {
			// Don't panic
			window.alert('GreenFox failed to send sample. Status='+xhr.status+','+xhr.responseText+'\ndata: '+postDataString);
			return false;
		}
	},
}

var mockCollect = {

	init: function() {},
	destroy: function() {},
	willSendSamples: function() {
		return false
	},

	/**
	 * Send sample.
	 * @param sample sample (number)
	 */
	postSample: function(sample) {
		return true // This is a mock
	},

}
