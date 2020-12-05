# buchmonitor
Monitoring CO2, temp and pH changed in kombucha brewing

I have a pet hypothesis that my buch cultures are able to utilise CO2. For months after they've been set up the pellicle continues to grow, with no extra addition of sugar. Where is carbon coming from for the cellulose in the pellicle?! Maybe they are drawing it from CO2 in the air?

Of course there are counter-hypotheses that the cellulose producing bacteria are eating the yeast and other organisms in the community, but it seems to go on for so long that there must be another carbon source.

To test my hypothesis I building a little bioreactor-type device to monitor what happens in the jar. pH is a proxy for sugar depletion, this should gradually drop over time as the culture acidifies. Using a cheap MQ135 CO2 sensor, I'll monitor the CO2. I've copied some of Raven Neo's code for this. Once the pH has settled (I think this should be between 3-4 from experience with litmus pH paper), the CO2 levels should begin to drop as the community ceases sugar utilisation and switches to CO2 utilisation.

If my hypothesis is vindicated with this experiment, it will probably require further repeats using other sensors in a better equipped laboratory using gas chromatogrpahy. But this is a fun way to see if it might be true!

Sensors used: MQ135 gas sensor, 4502 pH electrode, DS18B20 temp sensor
