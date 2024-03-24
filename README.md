# VTOL

## Dev Log:

03/21: Setup influx db and grafana

Influx DB
https://docs.influxdata.com/influxdb/v2/install/

Grafana:
https://grafana.com/docs/grafana/latest/setup-grafana/installation/debian/

I'm just running these on my laptop for now haha.

03/23: I linked up Grafana to Influx! This is actually really nice.
This will definitely get the job done for development for now. It's just such a fast setup, ~maybe 1 hr to get analyze-able telemetry. And especially with historical analysis to be able to "debug" what went wrong perhaps.

However, my biggest gripe is that honestly with a 5s delay it won't really work for a flight dashboard. I might look into something else for realtime monitoring. Or some sort of "replay from SD card system". Or lastly setting up some sort of dual system. Stream to influxDB + push to grafana live.

For GNC dev, I think I want to be able to make sure the sim can publish to this.

Here's an example of the simple influx db:
![InfluxDB + Grafana](documentation/influx_and_grafana.jpg "Dummy data put in at 1s resolution, with 5s auto refresh")

Part 2 edit. I found this thread and I adjusted my min refresh interval to 100ms. And not gonna lie my computer is definitely struggling haha, but atleast the data is live. I can totally see how real time telemetry startups are a thing. This does solve my woes for now. I will see how this scales once I go from 2 datapoints to 50x data points at 50hz. I wonder if I have more load from the rendering or from the querying.

03/23:

I think I load-tested Grafana, and I think it will do the job. I will just need to split my realtime dashboard from my analysis dashboard. The realtime dashboard will have a short query window and fetch all datapoints and refresh quickly. The analysis dashboard will fetch data for the entire run, but have aggregation queries.

Optimistically: let's say I am using a 115200 baud rate radio. this means effectively 11520 bytes per second since the 10 to 1 baud to byte conversion.

If I run my FC at 100 HZ, then I can stream 115 bytes per second. This means I can stream 29 floats/integers of critical telemetry. Any more, and I'll have to clock down or pick which telemetry is most important. Or something extremely silly would be to have multiple radio links hahaha. If I clock down to 25Hz, then I can easily buy enough telemetry margin, so I'm sure 115200 baud 915 mhz telem radios will be fine.