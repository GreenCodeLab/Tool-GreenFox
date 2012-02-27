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
		//removed
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
