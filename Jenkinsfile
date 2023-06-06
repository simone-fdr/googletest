pipeline {
	agent any
	stages{
		stage('Build'){
			steps{
				sh 'echo "Building.."'
				sh 'chmod +x scripts/Linux-Build.sh'
				sh 'scripts/Linux-Build.sh'
				archiveArtifacts artifacts: '*', fingerprint: true
			}
	}
	stage('Test 1-8'){
		steps{
			sh 'echo "Running 1-8..."'
			sh 'chmod +x scripts/Linux-Run1.sh'
			sh 'scripts/Linux-Run1.sh'
		}
	}
	stage('Test 9'){
		steps{
			sh 'echo "Running 9..."'
			sh 'chmod +x scripts/Linux-Run2.sh'
			sh 'scripts/Linux-Run2.sh'

		}
	}
	stage('Test 10'){
		steps{
			sh 'echo "Running 10..."'
			sh 'chmod +x scripts/Linux-Run3.sh'
			sh 'scripts/Linux-Run3.sh'
		}
	}
	stage('Run main'){
		steps{
			sh 'echo "Running main..."'
			sh 'chmod +x scripts/Linux-RunMain.sh'
			sh 'scripts/Linux-RunMain.sh'
			sh 'cat src/build/output_file.txt'
		}
	}
	stage('Build Docker'){
		steps{
			script{
				sh 'docker build -t simone-fdr/googletest .'
			}
		}
	}
	stage('Push Docker'){
		steps{
			withCredentials([string(credentialsId: 'dockerhub-credentials', usernameVariable: 'DOCKERHUB_USERNAME', passwordVariable: 'DOCKERHUB_PASSWORD')]) {
	               	        sh "echo 'DOCKERHUB_USERNAME: $DOCKERHUB_USERNAME'"
			        sh "echo 'DOCKERHUB_PASSWORD: $DOCKERHUB_PASSWORD'"
				//sh 'docker login -u $DOCKERHUB_USERNAME -p $DOCKERHUB_PASSWORD'
				//sh 'docker push simone-fdr/googletest'
			}
		}
	}
}
}
