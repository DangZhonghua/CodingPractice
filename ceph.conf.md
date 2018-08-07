[monitor/cluster bootstrap](http://docs.ceph.com/docs/master/dev/mon-bootstrap/)
[Manual Deployment](http://docs.ceph.com/docs/master/install/manual-deployment/)
ceph cluster must have:
1. a logical name(cluster name)
2. cluster fsid (uuid)
3. secret keys( for manage cluster)
   


> For BootStrap ceph cluster:
> ceph monitors must be configured at first.
> 
cluster: a set of monitors
quorum: an active set of monitors consisting of a majority of the cluster. For successfully start the cluster the available monintors must be quorum of whole cluster monitors.

## Monitor Bootstrapping

1. **Unique Identifier**: The fsid is a unique identifier for the cluster, and stands for File System ID from the days when the Ceph Storage Cluster was principally for the Ceph Filesystem. Ceph now supports native interfaces, block devices, and object storage gateway interfaces too, so fsid is a bit of a misnomer.

2. **Cluster Name**: Ceph clusters have a cluster name, which is a simple string without spaces. The default cluster name is ceph, but you may specify a different cluster name. Overriding the default cluster name is especially useful when you are working with multiple clusters and you need to clearly understand which cluster your are working with.

For example, when you run multiple clusters in a federated architecture, the cluster name (e.g., us-west, us-east) identifies the cluster for the current CLI session. Note: To identify the cluster name on the command line interface, specify the Ceph configuration file with the cluster name (e.g., ceph.conf, us-west.conf, us-east.conf, etc.). Also see CLI usage (ceph --cluster {cluster-name}).

3. **Monitor Name**: Each monitor instance within a cluster has a unique name. In common practice, the Ceph Monitor name is the host name (we recommend one Ceph Monitor per host, and no commingling of Ceph OSD Daemons with Ceph Monitors). You may retrieve the short hostname with hostname -s. The Monitor name is called Monitor ***LOGOCAL ID***.The logical id should be unique across the cluster. It will be appended to mon. to logically describe the monitor in the Ceph cluster. For example, if the logical id is foo, the monitor’s name will be mon.foo. For most users, there is no more than one monitor per host, which makes the short hostname logical choice.[from](http://docs.ceph.com/docs/master/dev/mon-bootstrap/)

4. **Monitor Map**: ***Bootstrapping the initial monitor(s) requires you to generate a monitor map. The monitor map requires the fsid, the cluster name (or uses the default), and at least one host name and its IP address.***

5. **Monitor Keyring**: Monitors communicate with each other via a secret key. You must generate a keyring with a monitor secret and provide it when bootstrapping the initial monitor(s).

6. **Administrator Keyring**: To use the ceph CLI tools, you must have a client.admin user. So you must generate the admin user and keyring, and you must also add the client.admin user to the monitor keyring

```
However, as a best practice, we recommend creating a Ceph configuration file and populating it with the fsid, the mon initial members and the mon host settings.
You can get and set all of the monitor settings at runtime as well. However, a Ceph Configuration file may contain only those settings that override the default values. When you add settings to a Ceph configuration file, these settings override the default settings. Maintaining those settings in a Ceph configuration file makes it easier to maintain your cluster.
```

### Build monitor
1. log in the node target as monitor. The default ceph cluster configuration is: ***/etc/ceph****
2. Create 

## Public Network
> To configure a public network, add the following option to the [global] section of your Ceph configuration file.
[global]
        # ... elided configuration
        public network = {public-network/netmask}



Cluster Network

If you declare a cluster network, OSDs will route heartbeat, object replication and recovery traffic over the cluster network. This may improve performance compared to using a single network. To configure a cluster network, add the following option to the [global] section of your Ceph configuration file.


[global]
        # ... elided configuration
        cluster network = {cluster-network/netmask}