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
