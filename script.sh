- cd ECLAIR
# Prepare for build
- ../prepare.sh Debug
# Analyze the project
- ./analyze.sh
# Make the directory for ECLAIR project database
#- ssh eclair-gitlab@localhost "mkdir -p ~/gitlab/$CI_PROJECT_PATH/$CI_JOB_ID && rm -f ~/gitlab/$CI_PROJECT_PATH/last_$CI_COMMIT_BRANCH && ln -s ~/gitlab/$CI_PROJECT_PATH/$CI_JOB_ID ~/gitlab/$CI_PROJECT_PATH/last_$CI_COMMIT_BRANCH"
# Copy the project database
#- scp out/PROJECT.ecd eclair-gitlab@localhost:~/gitlab/$CI_PROJECT_PATH/$CI_JOB_ID
# Publish ECLAIR report link
#- echo "https://eclairit.com:3787/fs/home/eclair-gitlab/gitlab/$CI_PROJECT_PATH/$CI_JOB_ID/PROJECT.ecd"
# Create the ECLAIR badge
#- anybadge --label=ECLAIR --value=default --file=badge.svg
