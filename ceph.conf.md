[monitor/cluster bootstrap](http://docs.ceph.com/docs/master/dev/mon-bootstrap/)
[Manual Deployment](http://docs.ceph.com/docs/master/install/manual-deployment/)
![simple cluster](http://docs.ceph.com/docs/master/_images/ditaa-b67d58275cae03a5573d36907b437e36df685600.png)
ceph cluster must have:
1. a logical name(cluster name)
2. cluster fsid (uuid)
3. secret keys( for manage cluster)

For BootStrap ceph cluster:
ceph monitors must be configured at first. 
cluster: a set of monitors
quorum: an active set of monitors consisting of a majority of the cluster. For successfully start the cluster the available monintors must be quorum of whole cluster monitors.
A Ceph Storage Cluster run at least three deamon
1.  Ceph Monitor(ceph-mon)
2.  Ceph Manager(ceph-mgr)
3.  Ceph OSD Daemon(ceph-osd)

the followings are optinal:
1. Ceph Metadata Server(Ceph-mds)
2. Ceph object Storage(ceph gateway daemons radosgw)

## option name
All Ceph configuration options have a unique name consisting of words formed with lower-case characters and connected with underscore (_) characters.

When option names are specified on the command line, either underscore (_) or dash (-) characters can be used interchangeable (e.g., --mon-host is equivalent to --mon_host).

When option names appear in configuration files, spaces can also be used in place of underscore or dash.

## Metavariables
Metavariables simplify Ceph Storage Cluster configuration dramatically. When a metavariable is set in a configuration value, Ceph expands the metavariable into a concrete value at the time the configuration value is used. Ceph metavariables are similar to variable expansion in the Bash shell.
Ceph supports the following metavariables:
Name|Default|Example|Description
:---|:---:|:---:|:---
$cluster|ceph|/etc/ceph/$cluster.keyring|Expands to the Ceph Storage Cluster name. Useful when running multiple Ceph Storage Clusters on the same hardware.
$type|*|/var/lib/ceph/$type|Expands to a daemon or process type (e.g., mds, osd, or mon)
$id|*|/var/lib/ceph/$type/$cluster-$id|Expands to the daemon or client identifier. For osd.0, this would be 0; for mds.a, it would be a.
$host|*|*|Expands to the host name where the process is running.
$name|*|/var/run/ceph/$cluster-$name.asok|Expands to $type.$id.
$pid|*|var/run/ceph/$cluster-$name-$pid.asok|Expands to daemon pid.


## Configuration sections
Any given process or daemon has a single value for each configuration option. However, values for an option may vary across different daemon types even daemons of the same type. Ceph options that are stored in the monitor configuration database or in local configuration files are grouped into sections to indicate which daemons or clients they apply to.
These sections include:
Name|Example|Description
:---|:---|:---
global|log_file = /var/log/ceph/$cluster-$type.$id.log|Settings under global affect all daemons and clients in a Ceph Storage Cluster.
mon|mon_cluster_log_to_syslog = true|Settings under mon affect all ceph-mon daemons in the Ceph Storage Cluster, and override the same setting in global.
mgr|mgr_stats_period = 10|Settings in the mgr section affect all ceph-mgr daemons in the Ceph Storage Cluster, and override the same setting in global.
osd|osd_op_queue = wpq|Settings under osd affect all ceph-osd daemons in the Ceph Storage Cluster, and override the same setting in global.
mds|mds_cache_size = 10G|Settings in the mds section affect all ceph-mds daemons in the Ceph Storage Cluster, and override the same setting in global.
client|objecter_inflight_ops = 512|Settings under client affect all Ceph Clients (e.g., mounted Ceph Filesystems, mounted Ceph Block Devices, etc.) as well as Rados Gateway (RGW) daemons.



> Sections may also specify an individual daemon or client name. For example, mon.foo, osd.123, and client.smith are all valid section names.
Any given daemon will draw its settings from the global section, the daemon or client type section, and the section sharing its name. Settings in the most-specific section take precedence, so for example if the same option is specified in both global, mon, and mon.foo on the same source (i.e., in the same configurationfile), the mon.foo value will be used.
>Note that values from the local configuration file always take precedence over values from the monitor configuration database, regardless of which section they appear in.

## The Configuration File
On startup, Ceph processes search for a configuration file in the following locations:

1. `$`CEPH_CONF (i.e., the path following the $CEPH_CONF environment variable)
2. -c path/path (i.e., the -c command line argument)
3. /etc/ceph/$cluster.conf
4.  ~/.ceph/$cluster.conf
5. ./$cluster.conf (i.e., in the current working directory)
6.  On FreeBSD systems only, /usr/local/etc/ceph/$cluster.conf

where $cluster is the cluster’s name (default ceph).
The Ceph configuration file uses an ini style syntax. You can add comments by preceding comments with a pound sign (#) or a semi-colon (;). For example:
```
# <--A number (#) sign precedes a comment.
; A comment may be anything.
# Comments always follow a semi-colon (;) or a pound (#) on each line.
# The end of the line terminates a comment.
# We recommend that you provide comments in your configuration file(s).
```
## Config file section names
```
[global]
debug ms = 0

[osd]
debug ms = 1

[osd.1]
debug ms = 10

[osd.2]
debug ms = 10
```


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
1. log in the node target as monitor. The default ceph cluster configuration is: ***/etc/ceph****. Create the cluster configuration file:{$clustername}.conf.
2. Create fsid. fsid can be a guid, so uuidgen can generate it.
3. fsid = {uuid} fsid = a7f64266-0894-4f1e-a635-d0aeaca0e993
4. Add the initial monitor(s) into target conf file.
```
   mon initial members = {hostname}[,{hostname}]
   example: mon initial members = node1
```
5. The foregoing in step 4 give monitor ID, but how to access it. so need add IP address(es) of the initial monitor(s) in the cong file.
```
        mon host = {ip-address}[,{ip-address}]
        example: mon host = 192.168.0.1
```
6. Create a keyring for your cluster and generate a monitor secret key. This key is used between monitors.

```
        ceph-authtool --create-keyring /tmp/ceph.mon.keyring --gen-key -n mon. --cap mon 'allow *'
```
7. Generate an administrator keyring, generate a client.admin user and add the user to the keyring
```
sudo ceph-authtool --create-keyring /etc/ceph/ceph.client.admin.keyring --gen-key -n client.admin --set-uid=0 --cap mon 'allow *' --cap osd 'allow *' --cap mds 'allow *' --cap mgr 'allow *'
```
8. Generate a bootstrap-osd keyring, generate a client.bootstrap-osd user and add the user to the keyring.
```
sudo ceph-authtool --create-keyring /var/lib/ceph/bootstrap-osd/ceph.keyring --gen-key -n client.bootstrap-osd --cap mon 'profile bootstrap-osd'
```
9. Add the generated keys to the ceph.mon.keyring.
    ```
        sudo ceph-authtool /tmp/ceph.mon.keyring --import-keyring /etc/ceph/ceph.client.admin.keyring
        sudo ceph-authtool /tmp/ceph.mon.keyring --import-keyring /var/lib/ceph/bootstrap-osd/ceph.keyring
    ```
10. Generate a monitor map using the hostname(s), host IP address(es) and the FSID. Save it as /tmp/monmap:
    ```
    monmaptool --create --add {hostname} {ip-address} --fsid {uuid} /tmp/monmap
    example:
    monmaptool --create --add node1 192.168.0.1 --fsid a7f64266-0894-4f1e-a635-d0aeaca0e993 /tmp/monmap
    ```
11. Create a default data directory (or directories) on the monitor host(s). This directory is used to store monitor data such as various cluster map.
    ```
    sudo mkdir /var/lib/ceph/mon/{cluster-name}-{hostname}
    example:
    sudo -u ceph mkdir /var/lib/ceph/mon/ceph-node1
    ```
12. Populate the monitor daemon(s) with the monitor map and keyring.
    ```
    sudo -u ceph ceph-mon [--cluster {cluster-name}] --mkfs -i {hostname} --monmap /tmp/monmap --keyring /tmp/ceph.mon.keyring
    example:
    sudo -u ceph ceph-mon --mkfs -i node1 --monmap /tmp/monmap --keyring /tmp/ceph.mon.keyring
    ```
13. Touch the done file.Mark that the monitor is created and ready to be started:
    ```
     sudo touch /var/lib/ceph/mon/ceph-node1/done
    ```

14. Start the monitor(s).For most distributions, services are started via systemd now:
    ```
    sudo systemctl start ceph-mon@node1
    ```
15. Verify that the monitor is running.
    ```
    ceph -s
    ```

16. According to the foregoing description. the configuration may look like this:
```
[global]
fsid = {cluster-id}
mon initial members = {hostname}[, {hostname}]
mon host = {ip-address}[, {ip-address}]
public network = {network}[, {network}]
cluster network = {network}[, {network}]
auth cluster required = cephx
auth service required = cephx
auth client required = cephx
osd journal size = {n}
osd pool default size = {n}  # Write an object n times.
osd pool default min size = {n} # Allow writing n copies in a degraded state.
osd pool default pg num = {n}
osd pool default pgp num = {n}
osd crush chooseleaf type = {n}
```
---
```
[global]
fsid = a7f64266-0894-4f1e-a635-d0aeaca0e993
mon initial members = node1
mon host = 192.168.0.1
public network = 192.168.0.0/24
auth cluster required = cephx
auth service required = cephx
auth client required = cephx
osd journal size = 1024
osd pool default size = 3
osd pool default min size = 2
osd pool default pg num = 333
osd pool default pgp num = 333
osd crush chooseleaf type = 1
```

## adding OSDs
> Once you have your initial monitor(s) running, you should add OSDs. Your cluster cannot reach an active + clean state until you have enough OSDs to handle the number of copies of an object (e.g., osd pool default size = 2 requires at least two OSDs). After bootstrapping your monitor, your cluster has a default CRUSH map; however, the CRUSH map doesn’t have any Ceph OSD Daemons mapped to a Ceph Node.
> From ceph Luminous, there are two object stores configuration: BlueStore, FileStore

Ceph provides the ceph-volume utility, which can prepare a logical volume, disk, or partition for use with Ceph. The ceph-volume utility creates the OSD ID by incrementing the index. Additionally, ceph-volume will add the new OSD to the CRUSH map under the host for you. Execute ceph-volume -h for CLI details. The ceph-volume utility automates the steps of the Long Form below. To create the first two OSDs with the short form procedure, execute the following on node2 and node3:

### ceph-volume bluestore
#### Create OSD 
   ```
   ssh {node-name}
   sudo ceph-volume lvm create --data {data-path}
   example:
   ssh node1
   sudo ceph-volume lvm create --data /dev/hdd1
   ```
Alternatively, the creation process can be split in two phases (prepare, and activate):
1. Prepare the OSD.
   ```
   ssh {node-name}
   sudo ceph-volume lvm prepare --data {data-path} {data-path}

   example:
   ssh node1
   sudo ceph-volume lvm prepare --data /dev/hdd1
   ```
   Once prepared, the *ID* and *FSID* of the prepared OSD are required for activation. These can be obtained by listing OSDs in the current server:
   ```
   sudo ceph-volume lvm list
   ```
2. Activate the OSD
  ```
  sudo ceph-volume lvm activate {ID} {FSID}
  ex:
  sudo ceph-volume lvm activate 0 a7f64266-0894-4f1e-a635-d0aeaca0e993
  ```
### ceph-volume filestore
#### Create the OSD
```
ssh {node-name}
sudo ceph-volume lvm create --filestore --data {data-path} --journal {journal-path}
example:
ssh node1
sudo ceph-volume lvm create --filestore --data /dev/hdd1 --journal /dev/hdd2
```
Alternatively, the creation process can be split in two phases (prepare, and activate):
1. Prepare the OSD:
   ceph-volume lvm prepare --filestore --data {data-path} --journal {journal-path}
   example:
   ssh node1
   ceph-volume lvm prepare --filestore --data /dev/hdd1 --journal /dev/hdd2

once prepared, the ***ID*** and ***FSID*** of the prepared OSD are required for activaton. These can be obtained by listing OSDs in the current server:
``` ceph-volume lvm list ```

2. Activate the OSD:
  ``` ceph-volume lvm activate --filestore {ID} {FSID}
  ```
  example:
  ```
  ceph-volume lvm activate --filestore 0 a7f64266-0894-4f1e-a635-d0aeaca0e993
  ```

### step by step adding OSD
Without the benefit of any helper utilities, create an OSD and add it to the cluster and CRUSH map with the following procedure. To create the first two OSDs with the long form procedure, execute the following steps for each OSD.
1. log in the target osd machine and create UUID for the OSD. 
  ```UUID=${uuidgen}```
2. Generate a cephx key for the OSD. 
   ```OSD_SECRET=$(ceph-authtool --gen-print-key)```
3. Create the OSD ID.

4. Create the dafault directory on your new OSD
``` mkdir /var/lib/ceph/osd/ceph-$ID```
If the OSD is for a drive other than the OS drive, prepare it for use with Ceph, and mount it to the directory you just created.
        ```
        mkfs.xfs /dev/{DEV}
        mount /dev/{DEV} /var/lib/ceph/osd/ceph-$ID
        ```
5. Write the secret to the OSD keyring file.
        ```
        ceph-authtool --create-keyring /var/lib/ceph/osd/ceph-$ID/keyring --name osd.$ID --add-key $OSD_SECRET
        ```
6. Initialize the OSD data directory.
        ```
        ceph-osd -i $ID --mkfs --osd-uuid $UUID
        ```
7. Fix Ownership
        ```
        chown -R ceph:ceph /var/lib/ceph/osd/ceph-$ID
        ```
8. After you add an OSD to Ceph, the OSD is in your configuration. However, it is not yet running. You must start your new OSD before it can begin receiving data
For modern systemd distributions:
        ```
        systemctl enable ceph-osd@$ID
        systemctl start ceph-osd@$ID

        example:
        systemctl enable ceph-osd@12
        systemctl start ceph-osd@12
        ```

## network configuration




### Public Network
> To configure a public network, add the following option to the [global] section of your Ceph configuration file.
[global]
        # ... elided configuration
        public network = {public-network/netmask}



Cluster Network

If you declare a cluster network, OSDs will route heartbeat, object replication and recovery traffic over the cluster network. This may improve performance compared to using a single network. To configure a cluster network, add the following option to the [global] section of your Ceph configuration file.


[global]
        # ... elided configuration
        cluster network = {cluster-network/netmask}